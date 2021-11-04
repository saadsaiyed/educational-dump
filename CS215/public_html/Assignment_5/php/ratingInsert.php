<?php
    include 'DBS_Connection.php';
    
    $MID = $_GET["movieID"];
    $UID = $_SESSION["User_ID"];
    $msg = '';

    if (isset($_POST["submitted"]) && $_POST["submitted"]){
        $msg = 'Rating Inserted';
        $currentDate = date("Y-m-d h:i:sa");
        $rating = $_POST['search'];
        echo "rating : " . $rating;
        $insert = "UPDATE View_Table SET User_Rating = '$rating', Rate_Time = '$currentDate'
        WHERE User_ID = '$UID' AND Movie_ID = '$MID'";
        $result1 = runQuery($insert);
    }
    else{
        $msg = "Rating Not Inserted";
    }
    echo $msg;
    header("Location: ../movieLayout.php?movieID=$MID");
?>