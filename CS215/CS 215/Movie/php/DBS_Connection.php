<?php
    session_start();
    $mysqli = new mysqli( 'hercules.cs.uregina.ca', 'sas162' , 'Abcd@123', 'sas162');

    if($mysqli->connect_error){
        die("Connection Error" . mysqli_connect_error());
    }

    function queryError($query){
        if($result = mysqli_query($GLOBALS[mysqli],$query)){
            $rowCount = mysqli_num_rows($result);
            mysqli_free_result($result);
            return $rowCount;
        }
        else{
            die("Error {$GLOBALS[mysqli]->errno} : {$GLOBALS[mysqli]->error} <br>");
        }
    }

    function runQuery($query){
        if($result = mysqli_query($GLOBALS[mysqli],$query)){
            return $result;
        }
        else{
            die("Error {$GLOBALS[mysqli]->errno} : {$GLOBALS[mysqli]->error} <br>");
        }
    }

    function checkIfLoggedin(){
        if(!isset($_SESSION["User_ID"])){
            return false;
        }else{
            return true;
        }
    }