<?php
    session_start();
    include 'DBS_Connection.php';

    $MID = $_GET["movieID"];
    $UID = $_SESSION["User_ID"];
    $currentDate = date("Y-m-d h:i:sa");

    if(!checkIfLoggedin())
	{
        header("Location: ../movieLayout.php?movieID=$MID");
        exit();
    }
    else{
        $select = "SELECT * FROM View_Table WHERE Movie_ID = '$MID' AND User_ID = '$UID'";
        $result = runQuery($select);
    
        if($result->num_rows < 1){
            $insert = "INSERT INTO View_Table (Movie_ID, User_ID, Watch_Time, Is_Watched)
            VALUES ('$MID', '$UID', '$currentDate', 1)";
            $result = runQuery($insert);
        }
    
        header("Location: ../movieLayout.php?movieID=$MID");
    }
?>