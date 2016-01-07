<?php
$n = $_POST['n'];
$x = $_POST['x'];
$result = $x;
$fact = 1;
$minusDegree = -1;
for ($i = 3; $i <= $n; $i=$i+2)
{
    if ($i != 1) $fact = $fact * $i * ($i - 1);
    $result = $result + $minusDegree*pow($x, $i)/$fact;
    $minusDegree = $minusDegree * (-1);
}
echo $result;
?>
