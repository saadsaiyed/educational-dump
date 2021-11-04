<?php
    include 'php/DBS_Connection.php';
    session_start();

    $MID = $_GET["movieID"];
    $UID = $_SESSION["User_ID"];
?>

<!DOCTYPE html>
<html>
    <head>
        <title>
            MovieTitle
        </title>
        <link rel="stylesheet" type="text/css" href="index_styling.css" />
        <style>
            .grid-container {
                display: grid;
                grid-template-columns: repeat(8, 1fr);
                grid-template-rows: repeat(12, 1fr);
                background-color: #333;
                grid-gap:1em;
                padding: 1em;
            }

            .gridItem {
                background-color: white;
                padding: 1em;
            }

            .item1 {
                text-align:center;
                padding: 0;
                grid-column: 1 / 10;
                grid-row: 1 / 2;
            }

            .item2 {
                grid-column: 1 / 6;
                grid-row: 2 / 4;
            }
            
            .item3 {
                text-align: left;
                padding:0;
                grid-column: 1 / 6;
                grid-row: 4 / 8;
            }

            .item4 {
                padding: 0;
                grid-column: 6 / 10;
                grid-row: 2 / 8;
            }

            .item5 {
                grid-column: 1 / 10;
                grid-row: 8 / 13;
            }
            h3{
                text-align: center;
            }
            img{
                width:100%;
                height: 100%;
            }
        </style>
        <script>
            window.onload = function(event)
            {
                document.getElementById("ratingBox").addEventListener("submit", SearchBox, false);
            }
        </script>
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
        <!--end of navigation bar-->
        <div class="grid-container">
            <?php 
                $select = "SELECT * FROM Movie_Table WHERE Movie_ID = '$MID'";
                $result = runQuery($select);
                echo "Here";echo "Here";
                $row = mysqli_fetch_array($result)?>
                <div class="gridItem item1" >
                    <h1><?=$row['Movie_Name']?></h1>
                </div>
                <div class="gridItem item2">
                    <h3>General Information</h3><br/><br/>
                    Genre : <?=$row['Genre']?><br/><br/>
                    Director : <?=$row['Director']?><br/><br/>
                    Cast : <?=$row['Cast']?>
                </div>
                <div class="gridItem item3">
                    <h3>Details</h3><br/><br/>
                    <div style = "margin-right: 20px; padding: 20px;">
                        Year : <?=$row['Year']?><br/><br/>
                        Rating : <?=$row['Rating']?> / 10<br/><br/>
                        Origin: <?=$row['Origin']?><br/><br/>
                        <a href ="<?=$row['Wiki_Link']?>"><u>Click here</u></a> to Visit Wikipedia.<br/><br/>
                        <form id = "ratingBox" method="post" action = "php/ratingInsert.php?movieID=<?=$MID?>" enctype = "multipart/form-data">
                            <input type="hidden" name="submitted" value="1"/>
                            <table>
                                <tr><td><label id="srch_msg" class="err_msg"></label></td></tr>
                                <tr><td><input type="text" name="search" placeholder="Rate this out of 10" size="28"/></td>
                                <td><input type="submit" value="Submit"/></td></tr>
                            </table>
                        </form>
                    </div>
                    <a href="watchlist.php"><button style = "float: right; margin: 1em;">Add to Watchlist</button></a>
                </div>
                <div class="gridItem item4">
                    <img src = "posters/<?=$row['Poster']?>.jpg" alt = "<?=$row['Poster']?>" style="max-width: 900px; max-height: 870px">
                </div>
                <div class="gridItem item5">
                    <h3>Comments</h3>
                </div>
        </div>
    </body>
</html>