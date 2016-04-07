<?php
$n = $_POST['n'];
$digitCount = array(0,0,0,0,0,0,0,0,0,0);
$result = 0;
echo "I receive: ";
echo $n;
echo "<br>";
while ($n > 0){
    $digit = $n % 10;
    $digitCount[$digit] = $digitCount[$digit] + 1;
    $n = floor($n / 10);
}
$tens = 1;
for ($i = 0; $i <10; $i = $i + 1){
    for ($j = 1; $j <= $digitCount[$i]; $j = $j + 1){
        $result = $result + $i*$tens;
        $tens = $tens * 10;
    }
}
echo "After conversion: ";
echo $result;
echo "\n";
?>