<?php
    include 'DBS_Connection.php';
    
    if(! empty($_POST)){
        $target_dir = "uploads/";
        $target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
        $uploadOk = 1;
        $imageFileType = strtolower(pathinfo($target_file,PATHINFO_EXTENSION));
        
        //Image Verification
        {
            // Check if image file is a actual image or fake image
            if(isset($_POST["submit"])) {
                $check = getimagesize($_FILES["fileToUpload"]["tmp_name"]);
                if($check !== false) {
                    echo "File is an image - " . $check["mime"] . ".";
                    $uploadOk = 1;
                } else {
                    echo "File is not an image.";
                    $uploadOk = 0;
                }
                echo "<br>";
            }
            // Check if file already exists
            if (file_exists($target_file)) {
                echo "Sorry, file already exists.";
                $uploadOk = 0;
                echo "<br>";
            }
            // Check file size
            if ($_FILES["fileToUpload"]["size"] > 500000) {
                echo "Sorry, your file is too large.";
                $uploadOk = 0;
                echo "<br>";
            }
            // Allow certain file formats
            if($imageFileType != "jpg" && $imageFileType != "png" && $imageFileType != "jpeg"
            && $imageFileType != "gif" ) {
                echo "Sorry, only JPG, JPEG, PNG & GIF files are allowed.";
                $uploadOk = 1;
                echo "<br>";
            }
            // Check if $uploadOk is set to 0 by an error
            if ($uploadOk == 0) {
                echo "Sorry, your file was not uploaded.";
                echo "<br>";
            // if everything is ok, try to upload file
            } else {
                if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file)) {
                    echo "The file ". basename( $_FILES["fileToUpload"]["name"]). " has been uploaded.";
                    echo "<br>";
                } else {
                    echo "Sorry, there was an error uploading your file.";
                    echo "<br>";
                }
            }
        }
        
        $Fname = $_POST['fname'];
        $Lname = $_POST['lname'];
        $DOB = $_POST['dob'];
        $Phone = $_POST['phone'];
        $Email = $_POST['email'];
        $Uname = $_POST['uname'];
        $Pass = $_POST['password'];
        
        $insert = "INSERT INTO User_Table (First_Name, Last_Name, Username, E_mail, Password, Date_Of_Birth, Phone_Number, Is_LogedIn, Avtar) 
        VALUES ('$Fname', '$Lname', '$Uname', '$Email', '$Pass', '$DOB', '$Phone', '1', '$target_file')";

        $result = runQuery($insert);

        $insert = "SELECT User_ID FROM User_Table ORDER BY User_ID DESC";

        $result = runQuery($insert);
        $row = mysqli_fetch_array($result);
        $_SESSION['User_ID'] = $row['User_ID'];
    }
    header("refresh:0.5s; url=../login.html");
?>