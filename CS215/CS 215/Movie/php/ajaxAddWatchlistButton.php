<?php
    include 'DBS_Connection.php';

	session_start();
	$mysqli = new mysqli('localhost', 'sas162', 'Abcd@123', 'sas162');
	if ($mysqli->connect_error){
		die ("Connection failed: " . $mysqli->connect_error);
	}
	
    if(!checkIfLoggedin())
	{
        header("Location: ../login.php");
        exit();
	}
	
	$table = array(); //= 'No result found';
	$UID = $_SESSION['User_ID'];
	$select = "SELECT * FROM Watchlist_Table WHERE User_ID = '$UID'";
	$result = $mysqli->query($select);
	if($result->num_rows > 0){
		while($rowi = $result->fetch_array()){
			$table[] = $rowi;
		}
	}
	$respond = json_encode($table);
	echo $respond;
?>