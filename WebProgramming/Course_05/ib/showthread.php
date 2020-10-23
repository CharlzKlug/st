<?php

function makePostForm($threadID) {
    echo "<div class=\"newMessage\">\n";
    echo "<form action=\"/newpost.php\" method=\"post\" enctype=\"multipart/form-data\">\n";
    echo "Image: <input type=\"file\" name=\"fileToUpload\" id=\"fileToUpload\">\n";
    echo "Message: <textarea name=\"message\"></textarea>\n";
    echo "<input type=\"hidden\" name=\"thread_id\" value=\"$threadID\">\n";
    echo "<input type=\"submit\" value=\"Submit\">\n";
    echo "</form>\n";
    echo "</div>\n";
}

include 'settings.php';

// Create connection
$conn = new mysqli($server, $username, $password, "ib");

// Check connection
if($conn->connect_error) {
    die ("Connection failed: " . $conn->connect_error);
}

if(!isset($_GET["thread"]))
    die("No datas!");

$threadID = $_GET["thread"];
echo "<!DOCTYPE html>\n";
echo "<html>\n";
echo "<head>\n";
echo "<link rel=\"stylesheet\"\n";
echo "type=\"text/css\"";
echo "href=\"myStyle.css\" />";
echo "</head>\n";
echo "<body>\n";

echo "<script src=\"ib.js\"></script>";

makePostForm($threadID);

$res = $conn->query("SELECT id, dt, picture, message FROM posts WHERE thread_id = $threadID;");

for ($row_no = 0; $row_no < $res->num_rows; $row_no++) {
    $res->data_seek($row_no);
    $row = $res->fetch_assoc();
    $pic = "";
    if ($row['picture'] != null || $row['picture'] != NULL) {
        $pic = "<img onclick=\"myFunction(this)\" src=\"uploads/" . $row['picture'] . "\" class=\"pic\">";
    }
    #echo $row['id'] . " " . $row['dt'] . " " . $pic . " " . $row['message'] . "</br>\n" ;
    echo "<div class=\"message\">\n";
    echo $row['id'] . " " . $row['dt'] ;
    echo "<table>\n";
    echo "<tr>\n";
    echo "<td>" . $pic . "</td>\n";
    echo "<td>" . $row['message'] . "</td>\n";
    echo "</tr>\n";
    echo "</table>\n";
    echo "</div>\n";
}

echo "</body>\n";
echo "</html>\n";
