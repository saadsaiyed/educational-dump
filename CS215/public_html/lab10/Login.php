<?php
    session_start();

    if(isset($_SESSION["email"]))
	{
        header("Location: index.php");
        exit();
    }
    
    $validate = true;
    $reg_Email = "/^\w+@[a-zA-Z_]+?\.[a-zA-Z]{2,3}$/";
    $reg_Pswd = "/^(\S*)?\d+(\S*)?$/";

    $email = "";
    $error = "";

    if (isset($_POST["submitted"]) && $_POST["submitted"])
    {
        $email = trim($_POST["email"]);
        $password = trim($_POST["password"]);
        
        $db = new mysqli("localhost", "sas162", "Abcd@123", "sas162");
        if ($db->connect_error)
        {
            die ("Connection failed: " . $db->connect_error);
        }

        //add code here to select * from table User where email = '$email' AND password = '$password'
        // start with 
        $q = "SELECT * FROM User WHERE email = '$email' AND password = '$password'";
        
        $r = $db->query($q);
        $row = $r->fetch_assoc();

        if($email != $row["email"] && $password != $row["password"])
        {
            $validate = false;
        }
        else
        {
            $emailMatch = preg_match($reg_Email, $email);
            if($email == null || $email == "" || $emailMatch == false)
            {
                $validate = false;
            }
            
            $pswdLen = strlen($password);
            $passwordMatch = preg_match($reg_Pswd, $password);
            if($password == null || $password == "" || $pswdLen < 8 || $passwordMatch == false)
            {
                $validate = false;
            }
        }
        
        if($validate == true)
        {

            session_start();
            $_SESSION["email"] = $row["email"];
            header("Location: index.php");
            //$db->close();
            exit();
        }
        else 
        {
            $error = "The email/password combination was incorrect. Login failed.";
            $db->close();
        }
    }
?>

<!DOCTYPE html>
<html>
<head>
<title>Login</title>
<script type="text/javascript" src="Login.js"></script>
</head>
<body>
<h3>Login</h3>
<div style = "color:red"> <?=$error?></div>
<form id="formLogin" action="Login.php" method="post">
<input type="hidden" name="submitted" value="1"/>
<table>
<tr>
<td></td>
<td></td>
</tr>
<tr>
<td>Email</td>
<td>Password</td>
</tr>
<tr>
<td id="emailMsg"></td>
<td id="pswdMsg"></td>
</tr>
<td><input type="email" id="email" name="email" value=""/></td>
<td><input type="password" id="password" name="password"/></td>
<td><input type="submit" value="Login"/></td>
</tr>

<tr>
<td>No account? <a href="Signup.php">Sign up</a></td>
</tr>
</table>
</form>

<script type="text/javascript" src="LoginR.js"></script>
</body>
</html>