<?php

function makeNewThreadForm($boardID) {
    echo "<form action=\"/newthread.php\" method=\"post\" enctype=\"multipart/form-data\">";
    echo "New thread name: <input type=\"text\" name=\"thname\">";
    echo "<input type=\"hidden\" name=\"board_id\" value=\"$boardID\">";
    echo "<input type=\"submit\" value=\"Make new thread\"></form> ";
}

include 'settings.php';

// Create connection
$conn = new mysqli($server, $username, $password, "ib");

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$board_id = $_GET["board"];

$conn = new mysqli($server, $username, $password, "ib");

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$res = $conn->query("select * from boards where board_id=$board_id;");
$res->data_seek(0);
$row = $res->fetch_assoc();
echo $row['board_name'];
echo $row['board_description'];

makeNewThreadForm($board_id);
                                         
$res = $conn->query ("SELECT thread_id, thread_name FROM threads WHERE board_id = $board_id;");

for ($row_no = 0; $row_no < $res->num_rows; $row_no++) {
    if ($row_no != $res->num_rows) echo "--- Delimiter ---</br>";
    $res->data_seek($row_no);
    $row = $res->fetch_assoc();
    echo $row['thread_id'] . " " . $row['thread_name'] . "</br>";
}

?>
