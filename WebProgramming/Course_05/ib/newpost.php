<?php

function saveMessageToDatabase ($image, $message, $threadID) {

    include 'settings.php';

    // Create connection
    $conn = new mysqli($server, $username, $password, "ib");

    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    $queryStr = "";
    if ($image == "NULL") {
        $queryStr = "INSERT INTO posts (thread_id, message) values ($threadID, '$message');";
    } else {
        $queryStr = "INSERT INTO posts (thread_id, picture, message) values ($threadID, '$image', '$message');";
    }
    echo $str;
    if (mysqli_query($conn, $queryStr)) {
        echo "Success!";
    } else {
        echo "Error: " . $queryStr . " " . mysqli_error($conn);
    }
}

echo $_FILES["fileToUpload"]["name"];
echo $_POST["message"];
echo $_FILES["fileToUpload"];
echo "Thread ID: " . $_POST["thread_id"];

if ($_POST["message"] == "") {
    die ("Empty message not allowed");
}
$target_dir = "uploads/";
$target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
$uploadOk = 1;
$imageFileType = strtolower(pathinfo($target_file, PATHINFO_EXTENSION));

// Check if image file is an actual image or fake image
if (isset($_POST["submit"])) {
    $check = getimagesize($_FILES["fileToUpload"]["tmp_name"]);
    if ($check !== false) {
        echo "File is an image - " . $check["mime"] . ".";
        $uploadOk = 1;
    } else {
        echo "File is not an image.";
        $uploadOk = 0;
    }
}

// Check file size
if ($_FILES["fileToUpload"]["size"] > 500000) {
    echo "Sorry, your file is too large.";
    $uploadOk = 0;
}

// Allow certain file formats
if ($imageFileType != "jpg" && $imageFileType != "png" && $imageFileType != "jpeg" && $imageFileType != "gif") {
    echo "Sorry, only JPG, JPEG, PNG & GIF files are allowed.";
    $uploadOk = 0;
}

// Check if $uploadOk is set to 0 by an error
if ($uploadOk == 0) {
    echo "Sorry, your file was not uploaded.";
    saveMessageToDatabase("NULL", $_POST["message"], $_POST["thread_id"]);
} else {
    $newGenName = (date('YmdHis').rand(100,1000) . "." . $imageFileType);
    $apend = $target_dir . $newGenName;
    if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $apend)) {
        echo "The file " . $newGenName . " has been uploaded.";
        
        echo "<img src=\"$apend\">";

        saveMessageToDatabase($newGenName, $_POST["message"], $_POST["thread_id"]);
    } else {
        echo "Sorry, there was an error uploading your file.";
    }
}
?>
