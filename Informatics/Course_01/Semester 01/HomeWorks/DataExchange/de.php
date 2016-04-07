<?php
$myArray = array();

//Грузим данные в массив
for ($i = 0; $i < 10; $i = $i + 1){
    $myArray[$i] = $_POST["n{$i}"];
}

// Сортируем массив
for ($i = 0; $i < 9; $i = $i + 1){
    $minIndex = $i;
    for ($j = $i + 1; $j < 10; $j = $j + 1){
        if ($myArray[$j] < $myArray[$minIndex]) $minIndex = $j;
    }
    $temp = $myArray[$i];
    $myArray[$i] = $myArray[$minIndex];
    $myArray[$minIndex] = $temp;
}

// Вывод массива на страницу
for ($i = 0; $i < 10; $i = $i + 1){
    echo "{$i}: {$myArray[$i]} <br>";
}
?>