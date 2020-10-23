<?php
if (isset($_POST["thname"]) & isset($_POST["board_id"])) {
    echo "I recieved thread name: " . $_POST["thname"];
    echo "I recieved board id: ". $_POST["board_id"];

    include 'settings.php';

    // Create connection
    $conn = new mysqli($server, $username, $password, "ib");

    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    $threadName = $_POST["thname"];
    $boardID = $_POST["board_id"];

    // Check thread uniquety
    $res = $conn->query("SELECT COUNT(thread_id) FROM threads WHERE thread_name='$threadName' AND board_id=$boardID;");
    $res->data_seek(0);
    $row = $res->fetch_assoc();

    if ($row['COUNT(thread_id)'] == 0) {
        $str = "INSERT INTO threads (board_id, thread_name) VALUES ($boardID, '$threadName');";
        echo $str;
        $res = $conn->query($str);

        echo "Thread created!";
    } else {
        echo "Not unique thread!";
    }
    
} else {
    echo "No data!";
}
?>
