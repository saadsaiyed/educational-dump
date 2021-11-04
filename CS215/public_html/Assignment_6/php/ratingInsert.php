<?php
    include 'DBS_Connection.php';
    session_start();

    $MID = $_GET["movieID"];
    $UID = $_SESSION["User_ID"];
    $msg = '';

    if(!checkIfLoggedin())
	{
        header("Location: ../login.php");
        exit();
    }

    if (isset($_POST["submitted"]) && $_POST["submitted"] && $_POST['search'] > 0 && $_POST['search'] < 11){
        $currentDate = date("Y-m-d h:i:sa");
        $rating = $_POST['search'];
        $insert = "UPDATE View_Table SET User_Rating = '$rating', Rate_Time = '$currentDate'
        WHERE User_ID = '$UID' AND Movie_ID = '$MID'";
        $result1 = runQuery($insert);
        if($result1){
            $msg = 'Rating Inserted';
        }
        else{
            $msg = "Rating Not Inserted";
        }

        $select = "SELECT * FROM View_Table WHERE User_Rating AND Movie_ID = '$MID';";
        $result = runQuery($select);
        if($result->num_rows > 0){
            $avgRating = 0;
            while($row = mysqli_fetch_array($result)){
                $avgRating += $row['User_Rating'];
            }
            $avgRating /= $result->num_rows;

            $insertM = "UPDATE Movie_Table SET Rating = '$avgRating'
            WHERE Movie_ID = '$MID'";
            $resultM = runQuery($insertM);
        }
    }
    else{
        $msg = "Something went wrong";
    }
    header("Location: ../movieLayout.php?movieID=$MID&msg=$msg");
?>