<?php
    include 'DBS_Connection.php';
    session_start();
    if(! empty($_POST)){
        
        $Email = $_POST['email'];
        $Uname = $_POST['uname'];
        $Pass = $_POST['password'];
        
        $query = "SELECT * FROM User_Table WHERE E_mail = '$Email'";
        $result = runQuery($query);

        while ($row = mysqli_fetch_array($result)){
            
            if($row['Password'] == $Pass){
                $_SESSION["User_ID"] = $row["User_ID"];
                header("Location: ../index.php");
                exit();
            }
        }
        header("Location: ../login.php");
    }
?>