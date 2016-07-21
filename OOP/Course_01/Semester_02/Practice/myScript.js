var numLetters = [], firstMul, secondMul, firstResult, secondResult;
var isOpenFirstMul = []; // Элементы слева-направо
var isOpenSecondMul = [];
var isOpenFirstResult = [];
var isOpenSecondResult = [];
var isOpenResult = [];

genLetters();

function checkWin() {
    var allOpen = true;
    for (i = 0; i < 3; ++i) allOpen = allOpen && isOpenFirstMul[i];
    for (i = 0; i < 2; ++i) allOpen = allOpen && isOpenSecondMul[i];
    return allOpen;
}

function checkArray(someArray, someNumber, arrayLength, arrayNumber) {
    for (i = 0; i < arrayLength; ++i){
	if (someArray[i] == false && numLetters[someNumber] == document.getElementById('letter' + arrayNumber + (i + 1)).innerHTML){
	    someArray[i] = true;
	    document.getElementById('letter' + arrayNumber + (i + 1)).innerHTML = someNumber;
	}
    }
}

function fillTable() {
    isOpenFirstMul = [false, false, false];
    isOpenSecondMul = [false, false];
    isOpenFirstResult = [false, false, false, true];
    isOpenSecondResult = [false, false, false, true];
    isOpenResult = [false, false, false, false, true];
    var t;

    // firstMul
    t = Math.floor(Math.random() * 10);
    document.getElementById('letter11').innerHTML = numLetters[t];
    firstMul = t;
    t = Math.floor(Math.random() * 10);
    document.getElementById('letter12').innerHTML = numLetters[t];
    firstMul += t * 10;
    t = Math.floor(Math.random() * 9) + 1;
    document.getElementById('letter13').innerHTML = numLetters[t];
    firstMul += t * 100;

    // secondMul
    t = Math.floor(Math.random() * 10);
    document.getElementById('letter21').innerHTML = numLetters[t];
    secondMul = t;

    // Заполнение первого ряда умножения столбиком
    var k;
    firstResult = firstMul * t;
    if (firstResult > 999) {
	isOpenFirstResult[3] = false;
	k = 4;
    }
    else k = 3;
    for (i = 1; i <= k; ++i) {
	document.getElementById('letter3'+i).innerHTML = numLetters[firstResult % 10];
	firstResult = Math.floor(firstResult / 10);
    }

    // Генерация второго множителя
    t = Math.floor(Math.random() * 9) + 1;
    document.getElementById('letter22').innerHTML = numLetters[t];
    secondMul += t * 10;

    // Заполнение второго ряда умножения столбиком
    secondResult = firstMul * t;
    if (secondResult > 999) {
	isOpenSecondResult[3] = false;
	k = 4;
    }
    else k = 3;
    for (i = 1; i <= k; ++i) {
	document.getElementById('letter4'+i).innerHTML = numLetters[secondResult % 10];
	secondResult = Math.floor(secondResult / 10);
    }
    
    // Обработка результата умножения
    temp = firstMul * secondMul;
    if (temp > 9999) {
	isOpenFirstResult[4] = false;
	k = 5;
    }
    else k = 4;
    for (i = 1; i <= k; ++i) {
	document.getElementById('letter5'+i).innerHTML = numLetters[temp % 10];
	temp = Math.floor(temp / 10);
    }
    console.log(firstMul);
    console.log(secondMul);
    
    
    
}

function getNumber(someArray, id) {
    if (someArray[id.slice(1,2) - 1] == false) {
	var someNumber = prompt("Please enter number", 0);
	if (numLetters[someNumber] == document.getElementById('letter' + id).innerHTML) {
//	    document.getElementById('letter' + id).innerHTML = someNumber;
//	    someArray[id.slice(1,2) - 1] = true;
	    //	    checkArrays(someNumber);
	    checkArray(isOpenFirstMul, someNumber, 3, 1);
	    checkArray(isOpenSecondMul, someNumber, 2, 2);
	    checkArray(isOpenFirstResult, someNumber, 4, 3);
	    checkArray(isOpenSecondResult, someNumber, 4, 4);
	    checkArray(isOpenResult, someNumber, 5, 5);
	    if (checkWin() == true) {
		openTable();
		if (confirm("Вы победили! Начать новую игру?") == true) fillTable();
	    }
	}
    }
}

function openTable() {
    
}

function inputNumber(element) {
    var id = element.id;
    var row = id.slice(0,1);
    // row:
    // 1 - массив isOpenFirstMul
    // 2 - массив isOpenSecondMul
    // 3 - массив isOpenFirstResult
    // 4 - массив isOpenSecondResult
    // 5 - массив isOpenResult
    
    var element = id.slice (1,2); // element - 1 --- номер элемента в массиве
    switch (row) {
    case "1":
	getNumber(isOpenFirstMul, id);
	break;
    case "2":
	getNumber(isOpenSecondMul, id);
	break;
    case "3":
	getNumber(isOpenFirstResult, id);
	break;
    case "4":
	getNumber(isOpenSecondResult, id);
	break;
    case "5":
	getNumber(isOpenResult, id);
	break;
    }
    console.log(row + "-" + element);
}

function genLetters() {
    var letters = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K'];
    var cS; // currentSymbol - текущий символ
    for (i = 0; i < 9; ++i) {
	cS = Math.round(Math.random() * (9 - i));
	numLetters[i] = letters[cS];
	for (k = cS; k < 9 - i; ++k) {
	    letters[k] = letters[k + 1];
	}
    }
    numLetters[9] = letters[0];
}

