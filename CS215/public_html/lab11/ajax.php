<?php
	$letter = $_POST['q'];
	$mysqli = new mysqli('localhost', 'sas162', 'Abcd@123', 'sas162');
	if ($mysqli->connect_error){
		die ("Connection failed: " . $mysqli->connect_error);
	}
	
	$row = array(); //= 'No result found';

	$select = "SELECT * FROM User WHERE email LIKE '$letter%'";
	$result = $mysqli->query($select);
	if($result->num_rows > 0){
		while($rowi = $result->fetch_array()){
			$row[] = $rowi;
		}
	}
	$respond = json_encode($row);
	echo $respond;
?> 