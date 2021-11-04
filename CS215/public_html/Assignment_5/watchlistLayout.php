<?php
    include 'php/DBS_Connection.php';
    $watchlistID = $_GET['watchlistID'];
    $query = "SELECT * FROM Watchlist_Table WHERE Watchlist_ID = '$watchlistID'";
    $result = mysqli_query($mysqli,$query);
    $row = mysqli_fetch_array($result);
?>

<!DOCTYPE html>
<html lang="en">
    <head>
        <title>Watchlist</title>
        <link rel="stylesheet" type="text/css" href="index_styling.css" />
        <style>
            .container{
                display: grid;
                grid-template-columns: repeat(9, 1fr);
                grid-template-rows: repeat(6, 1fr);
                background-color: #333;
                grid-gap:1em;
                padding: 1em;
                }
            .gridItem{
                text-align: center;
                padding: 1em;
                background-color: white;
                border-radius: 30px;     
            }
            .item1{
                grid-column: 1/4;
                grid-row: 1/4;
            }
            .item2{
                grid-column: 4/7;
                grid-row: 1/4;
            }
            .item3{
                grid-column: 7/10;
                grid-row: 1/4;
            }
            .item4{
                grid-column: 1/4;
                grid-row: 4/7;
            }
            .p1{
                max-width: 500px;
                max-height: 400px;
                min-width: 500px;
                min-height: 400px;
                box-shadow: 0 5px 10px #0000001a;
            }
        </style>
    </head>
    <body>
        <header>
            <img src="image/swag.png" alt="swag" style= "max-width: 300px; max-height: 200px;">
            <div style = "margin-bottom: 1px;">SwaggerSoul</div>    
        </header>
        <!-- This is for the Navigation bar -->
        <!------------------------------------------------------------------------------------------------------------>
        <ul>
            <li><a href = "index.php">Home</a></li>
            <li class="dropdown"><a>Genre</a>
                <div class="dropdown-content">
                    <a href = "genre.php">Action</a>
                    <a href = "genre.php">Adventure</a>
                    <a href = "genre.php">Biography</a>
                    <a href = "genre.php">Comedy</a>
                    <a href = "genre.php">Crime</a>
                    <a href = "genre.php">Drama</a>
                    <a href = "genre.php">Family</a>
                    <a href = "genre.php">Fantasy</a>
                    <a href = "genre.php">Horror</a>
                    <a href = "genre.php">Musical</a>
                    <a href = "genre.php">Mystery</a>
                    <a href = "genre.php">Patriotic</a>
                    <a href = "genre.php">Romance</a>
                    <a href = "genre.php">Sci-fi</a>
                    <a href = "genre.php">Social</a>
                    <a href = "genre.php">Sports</a>
                    <a href = "genre.php">Spy</a>
                    <a href = "genre.php">Suspense</a>
                    <a href = "genre.php">Thriller</a>
                    <a href = "genre.php">War</a>
                    <a href = "genre.php">Western</a>
                    <a href = "genre.php">Wuxia</a>
                    <a href = "genre.php">Zombie</a>
                </div>
            </li>
            <li class="dropdown"><a>Origin</a>
                <div class="dropdown-content">
                    <a href = "origin.php">American</a>
                    <a href = "origin.php">Australian</a>
                    <a href = "origin.php">Bollywood</a>
                    <a href = "origin.php">British</a>
                    <a href = "origin.php">Canadian</a>
                    <a href = "origin.php">Chinese</a>
                    <a href = "origin.php">Japanese</a>
                    <a href = "origin.php">Punjabi</a>
                    <a href = "origin.php">Russian</a>
                </div>
            </li>
            <li><a href = "contactUs.php">Contact Us</a></li>

            <!-- Watchlist varifiaction -->
            <li><a href = "watchlist.php">Watchlist</a></li>
            
            <!-- Login/Signup and Logout -->
            <?php 
            	if(!checkIfLoggedin()){
                    echo '<li style="float:right;"><a style="margin: 0em 2em;" class="highlighted" href = "signup.php">Signup</a></li>
                        <li style="float:right;"><a class="highlighted" href = "login.php">Login</a></li>';
                }
                else{
                    echo '<li style="float:right;"><a style="margin: 0em 2em;" class="highlighted" href = "logout.php">Logout</a></li>';
                }
            ?>
        </ul>
        <!------------------------------------------------------------------------------------------------------------>
        <center><h1 style = ""><?=$row['Watchlist_Name']?></h1></center>
        <div class = "container">
            <div class = "gridItem"><a href = "addWatchlistMovie.php?watchlistID=<?=$watchlistID?>"><img class = "p1" src="image/addNewPlaceholder.png" alt = "img1" style="box-shadow: 0 0 0;"></a><br/><h2>Add Movie</h2></div>
            <div class = "gridItem"><a href = "removeWatchlistMovie.php?watchlistID=<?=$watchlistID?>"><img class = "p1" src="image/removePlaceholder.png" alt = "img1" style="box-shadow: 0 0 0;"></a><br/><h2>Remove Movie</h2></div>
            <?php
                $query = "SELECT * FROM Bridge WHERE Watchlist_ID = $watchlistID";
                $result = runQuery($query); $i = 1;

                while($row = mysqli_fetch_array($result)){
                    $mID = $row['Movie_ID'];
                    $query1 = "SELECT * FROM Movie_Table WHERE Movie_ID = $mID";
                    $result1 = runQuery($query1); $i = 1;
                    $row1 = mysqli_fetch_array($result1);
                    ?>
                    <div class = "gridItem">
                        <a href = "php/watchedMovie.php?movieID=<?=$row['Movie_ID']?>"><img class = "p1" src = "posters/<?=$row1['Poster']?>.jpg" alt = "<?=$row1['Poster']?>">
                            <h2><?=$row1['Movie_Name']?> (<?=$row1['Year']?>)</h2><br/>Rating: <?=$row1['Rating']?> / 10
                        </a><br/>
                        Created on: <?=$row['Add_Time']?>
                    </div>
            <?}?>
        </div>
    </body>
</html>
