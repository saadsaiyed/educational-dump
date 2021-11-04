<?php
    session_start();
    if(isset($_SESSION["email"]))
	{
        header("Location: index.php");
        exit();
	}
    $db = new mysqli("localhost", "sas162", "Abcd@123", "sas162");
    $validate = true;
    $error = "";
    $reg_Email = "/^\w+@[a-zA-Z_]+?\.[a-zA-Z]{2,3}$/";
    $reg_Pswd = "/^(\S*)?\d+(\S*)?$/";
    $reg_Bday = "/^\d{1,2}\/\d{1,2}\/\d{4}$/";
    $email = "";
    $date = "mm/dd/yyyy";


    if (isset($_POST["submitted"]) && $_POST["submitted"]){
        if ($db->connect_error){
            die ("Connection failed: " . $db->connect_error);
        }
        echo "hello";
        $email = trim($_POST["email"]);
        $date = trim($_POST["date"]);
        $password = trim($_POST["password"]);

        $q1 = "SELECT * FROM User WHERE email = '$email'";
        $r1 = $db->query($q1);

        //Verifiying the input
        if($r1->num_rows > 0){
            $validate = false;
        }
        else{
            //checking if there are any syntex error in the text which id email verification
            $emailMatch = preg_match($reg_Email, $email);
            if($email == null || $email == "" || $emailMatch == false)
            {
                $validate = false;
            }
            
                
            $pswdLen = strlen($password);
            $pswdMatch = preg_match($reg_Pswd, $password);
            if($password == null || $password == "" || $pswdLen< 8 || $pswdMatch == false)
            {
                $validate = false;
            }

            $bdayMatch = preg_match($reg_Bday, $date);
            if($date == null || $date == "" || $bdayMatch == false)
            {
                $validate = false;
            }
        }

        //=======================================================

        if($validate == true)
        {
            $dateFormat = date("Y-m-d", strtotime($date));
            //add code here to insert a record into the table User;
            $q2 = "INSERT INTO User (DOB, email, password) VALUES ('$dateFormat', '$email', '$password')";
            // table User attributes are: email, password, DOB
            // variables in the form are: email, password, dateFormat, 
            // start with $q2 =
           
            $r2 = $db->query($q2);
            
            if ($r2 === true)
            {
                header("Location: Login.php");
                $db->close();
                exit();
            }
        }
        else
        {
            $error = "email address is not available. Signup failed.";
            $db->close();
        }

        //=======================================================
        
    }
?>


<!DOCTYPE html>
<html>
<head>
<title>Sign Up</title>
<script type="text/javascript" src="Signup.js"></script>
</head>
<body>
<h3>Sign up </h3>
<div style = "color:red"> <?=$error?></div>
<form id="formSignup" action="Signup.php" method="post">
<input type="hidden" name="submitted" value="1"/>
<table>
<tr>
<td></td>
<td></td>
</tr>
<tr>
<td></td>
<td id="email_S"></td>
</tr>
<tr>
<td>Email</td>
<td><input type="email" id="email" name="email" value=""/></td>
</tr>
<tr>
<td></td>
<td id="pswd_S"></td>
</tr>
<tr>
<td>Password</td>
<td><input type="password" id="password" name="password"/></td>
</tr>

<tr>
<td></td>
<td id="date_S"></td>
</tr>
<tr>
<td>Birthday</td>
<td><input type="text" id="date" name="date" value="mm/dd/yyyy"/></td>
</tr>

<tr>
<td></td>
<td><input type="submit" value="Sign up"/><input type="reset" value="Reset"/></td>

</tr>
</table>
</form>
<script type="text/javascript" src="SignupR.js"></script>
</body>
</html>
