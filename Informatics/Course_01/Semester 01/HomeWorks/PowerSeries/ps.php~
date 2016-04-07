<?php
$n = $_POST['n'];
$x = $_POST['x'];
$result = $x;
$fact = 1;
for ($i = 3; $i <= $n; $i=$i+2)
{
    if ($i != 1) $fact = $fact * $i * ($i - 1);
    $result = $result + pow(-1, $i)*pow($x, $i)/$fact;
}
echo $result;
echo "\n";
?>
