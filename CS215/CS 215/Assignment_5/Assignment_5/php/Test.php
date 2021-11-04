<?php
$con=mysqli_connect("localhost","sas162","Abcd@123","sas162");
// Check connection
if (mysqli_connect_errno())
{
echo "Failed to connect to MySQL: " . mysqli_connect_error();
}

$result = mysqli_query($con,"SELECT * FROM Movie_Table");

echo "<table border='1'>
<tr>
<th>Movie_ID</th>
<th>Movie_Name</th>
<th>Year</th>
<th>Rating</th>
<th>Poster</th>
<th>Director</th>
<th>Cast</th>
<th>Wiki_Link </th>
<th>Genre</th>
<th>Origin</th>
</tr>";

while($row = mysqli_fetch_array($result))
{
echo "<tr>";
echo "<td>" . $row['Movie_ID'] . "</td>";
echo "<td>" . $row['Movie_Name'] . "</td>";
echo "<td>" . $row['Year'] . "</td>";
echo "<td>" . $row['Rating'] . "</td>";
echo "<td>" . $row['Poster'] . "</td>";
echo "<td>" . $row['Director'] . "</td>";
echo "<td>" . $row['Cast'] . "</td>";
echo "<td>" . $row['Wiki_Link'] . "</td>";
echo "<td>" . $row['Genre'] . "</td>";
echo "<td>" . $row['Origin'] . "</td>";
echo "</tr>";
}
echo "</table>";

mysqli_close($con);
?>