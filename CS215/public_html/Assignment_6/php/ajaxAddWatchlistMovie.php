<?php
	$MID = $_GET['MID'];
	$WID = $_GET['WID'];
	$currentDate = date("Y-m-d h:i:sa");
	
	$mysqli = new mysqli('localhost', 'sas162', 'Abcd@123', 'sas162');
	if ($mysqli->connect_error){
		die ("Connection failed: " . $mysqli->connect_error);
	}

	$select = "INSERT INTO Bridge (Movie_ID, Watchlist_ID, Add_Time) VALUES ('$MID', '$WID', '$currentDate')";
	$result = $mysqli->query($select);
	if($result)
		echo 1;
	else
		echo 0;
?>