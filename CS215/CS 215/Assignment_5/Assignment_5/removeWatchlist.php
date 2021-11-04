<?php
    include 'php/DBS_Connection.php';

    $error = "";

    if (!empty($_POST)){
        $PName = $_POST['playlist'];

        $checkQuery = "SELECT * FROM Watchlist_Table WHERE Watchlist_Name = '$PName'";
        $result = runQuery($checkQuery);
        
        if($result->num_rows > 0){
            $query = "DELETE FROM Watchlist_Table WHERE Watchlist_Name = '$PName'";
            $result = runQuery($query);
            header("Location: watchlist.php");
            exit();
        }
        else{
            $error = "No Playlist Found";
        }
    }
?>

<!DOCTYPE html>
<html>
<head>
    <title>Remove Watchlist</title>
    <script>
        window.onload = function(event){
            document.getElementById("playlistForm").addEventListener("submit", PlaylistForm, false);
        }
    </script>
    <link rel="stylesheet" type="text/css" href="index_styling.css"/>
    <script type = "text/javascript"  src = "playlistValidation.js" ></script>
    <style>
        body{
            background: #333;
        }
        .container {
            background: #fff;
            border-radius: 20px;
            border: 10px solid #ccc;
            box-shadow: 0 1px 2px #0000001a;
        }
        form {
            padding: 2em;
        }
        label {
            color: #555;
            display: inline-block;
            padding-top: 10px;
            font-size: 20px;
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

    <div class="container">
        <form id = "playlistForm" method="post" action="removeWatchlist.php">
        <div style = "color:red"> <?=$error?></div>
            <table>
                <tr><td></td><td><label id="plist_msg" class="err_msg"></label></td></tr>
                <tr><td>Playlsit Name: </td><td> <input type="text" name="playlist" size="28" onkeyup="charCount(this.value)"/></td></tr>
                <tr><td></td><td><label id="count_msg" class="err_msg"></label></td></tr>
            </table><br/>
            <input type="submit" value="Sig up"/>
        </form>
    </div>
</body>
</html>