<?php
    include 'php/DBS_Connection.php';
?>

<!DOCTYPE html>
<html>
    <head>
        <title>Login</title>
        <link rel="stylesheet" type="text/css" href="index_styling.css" />
        <script type="text/javascript" src="logInValidation.js"> </script> 
        <script type = "text/javascript"  src = "logInEvent.js" ></script>
        <style>
            body{
                align-content: center;
                background: #333;
            }
            a{
                display: block;
                text-decoration: none;
                color: black;
            }
            .container {
                background: #fff;
                padding: 2em;
                padding-left: 4em;
                padding-right: 4em;
                border-radius: 20px;
                border: 10px solid #ccc;
                box-shadow: 0 1px 2px #0000001a;
                display: inline-block;
            }
            label {
                color: #555;
                display: inline-block;
                padding-top: 10px;
                font-size: 20px;
            }
            img{
                width:300px;
                height:200px;
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

        <center>
            <div class="container">
                <h1>Login</h1>
                <form id="SignUp" method="post" action="php/loginUserData.php">
                    <table>
                        <tr><td></td><td>
                            <label id="email_msg" class="err_msg"></label>
                        </td></tr>
                        <tr><td>Email: </td><td>
                            <input type="text" name="email" size="28" />
                        </td> </tr>
                        
                        <tr><td></td><td>
                            <label id="pswd_msg" class="err_msg"></label>
                        </td></tr>
                        <tr><td>Password: </td><td> 
                            <input type="password" name="password" size="28"/>
                        </td></tr>
                    </table>
                    <br/>
                    <input type="submit" value="LogIn" />
                    <input type="reset" value="Reset" /><br/><br/>
                    <a href = "signup.php"><input type="button" value="Signup"/></a><br/>
                    <a href = "index.php"><input type="button" value="Guest"/></a>
                </form>
            </div>
        </center>
    </body>
</html>