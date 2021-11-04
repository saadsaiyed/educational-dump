<?php
	$M_Name = $_GET['M_Name'];
	$mysqli = new mysqli('localhost', 'sas162', 'Abcd@123', 'sas162');
	if ($mysqli->connect_error){
		die ("Connection failed: " . $mysqli->connect_error);
	}
	
	$row = array(); //= 'No result found';

	$select = "SELECT * FROM Movie_Table ORDER BY $M_Name LIMIT 15";
	if($M_Name === 'Rating'){
		$select = "SELECT * FROM Movie_Table WHERE $M_Name ORDER BY $M_Name Desc LIMIT 15";
	}
	
	$result = $mysqli->query($select);
	if($result->num_rows > 0){
		while($rowi = $result->fetch_array()){
			$row[] = $rowi;
		}
	}
	$respond = json_encode($row);
	echo $respond;
?>