<?php
	$letter = $_GET['search'];
	$mysqli = new mysqli('localhost', 'sas162', 'Abcd@123', 'sas162');
	if ($mysqli->connect_error){
		die ("Connection failed: " . $mysqli->connect_error);
	}
	
	$row = array(); //= 'No result found';

	$select = "SELECT Movie_Name FROM Movie_Table WHERE Movie_Name LIKE '%$letter%'";
	$result = $mysqli->query($select);
	if($result->num_rows > 0){
		while($rowi = $result->fetch_array()){
			$row[] = $rowi;
		}
	}
	$respond = json_encode($row);
	echo $respond;
?> 