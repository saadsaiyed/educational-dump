<?php
    include 'php/DBS_Connection.php';
    session_start();
    if(!checkIfLoggedin())
	{
        header("Location: login.php");
        exit();
	}
?>

<!DOCTYPE html>
<html lang="en">
    <head>
        <title>Watchlist</title>
        <link rel="stylesheet" type="text/css" href="index_styling.css" />
        <style>
            .container{
                display: grid;
                grid-template-columns: repeat(3, 1fr);
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
            .p1{
                max-width: 500px;
                max-height: 400px;
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
        <a href = "addWatchlist.php"><button style = "background-color: #333; color: white; border-radius: 1rem;">Add Playlist</button></a>
        <a href = "removeWatchlist.php"><button style = "background-color: #333; color: white; border-radius: 1rem;">Remove Playlist</button></a><br/><br/>
        <div class = "container">
            <?php
                $u_ID = $_SESSION['User_ID'];
                $query = "SELECT * FROM Watchlist_Table WHERE User_ID = $u_ID";
                $result = runQuery($query); $i = 1;
                while($row = mysqli_fetch_array($result)){?>
                    <div class = "gridItem">
                        <?php if(checkIfLoggedin()){?>
                                <a href = "watchlistLayout.php?watchlistID=<?=$row["Watchlist_ID"]?>">
                        <?  }else{?>
                                <a href = "login.php">
                        <?  }?>
                        <img class = "p1" src="image/playlistPlaceholder.png" alt = "img<?=$i?>">
                        </a>
                        <br/><h2><?=$row['Watchlist_Name']?></h2>
                        Created on: <?=$row['Create_Time']?>
                    </div>
                <?$i++;}
            ?>
        </div>
    </body>
</html> 