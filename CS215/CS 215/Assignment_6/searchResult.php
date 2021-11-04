<?php
    include 'php/DBS_Connection.php';
    session_start();
?>
<!DOCTYPE html>
<html lang="en">
    <head>
        <title>SwaggerSoul</title>
        <script>
            window.onload = function(event)
            {
                document.getElementById("searchBox").addEventListener("submit", SearchBox, false);
            }
        </script>
        <script type = "text/javascript"  src = "searchBoxValidation.js"></script>
        <link rel="stylesheet" type="text/css" href="index_styling.css" />
        <style>
            .grid-container {
                position: relative;
                display: grid;
                grid-gap: 1em;
                grid-template-columns: repeat(10, minmax(auto, 300px));
                background-color: #333;
                padding: 1em;
            }
            .grid-item:nth-child(odd){
                padding: 1em;
                padding-right: 2em;
                grid-column: 1 / 3;
                text-align: center;
                font-size: 30px;
            }
            .grid-item:nth-child(even) {
                text-align: left;
                background-color: white;
                grid-column: 3 / 11;
                padding:1em;
                font-size: 30px;
                border-radius: 30px;
            }
            img{
                max-width: 300px;
            }
            a{
                color: white;
            }
            #searchBox{
                margin-bottom: 1em;
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
        <!-- Major body starts from here -->

        <div class="grid-container">
            <?php
                $search = $_POST['search'];
                $select = "SELECT * FROM Movie_Table WHERE Movie_Name LIKE '%$search%'";
                $result = runQuery($select);

                if($result->num_rows > 0){
                    while($row = mysqli_fetch_array($result)){?>
                        <div class="grid-item">
                            <a href="php/watchedMovie.php?movieID=<?=$row['Movie_ID']?>">
                                <img src = "posters/<?=$row['Poster']?>.jpg" alt = "<?=$row['Movie_Name']?>">
                                <h3><?=$row['Movie_Name']?> (<?=$row['Year']?>)</h3>
                            </a>
                        </div>
                        <div class="grid-item">
                            <h4><?=$row['Genre']?></h4>
                            <h4>General Information</h4>
                            Director : <?=$row['Director']?><br/><br/>
                            Cast : <?=$row['Cast']?><br/><br/>
                            Rating : <?=$row['Rating']?> / 10
                            <input type="hidden" name="movie_id" value = "<?$row['Movie_ID']?>"/>
                            <a href="watchlist.html"><button style = "float: right;">Add to Watchlist</button></a>
                        </div>
                    <?}
                }
                else{
                    echo "No Result found";
                    header("refresh:2s; url=../login.html");
                }?>
        </div>
    </body>
</html>