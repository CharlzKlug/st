#include "lab_03.h"

bool menuFromFile (string fileName, string *sa, int menuCount)
{   // Чтение элементов меню из файла и занесение в массив *sa.
    char *cstr = new char[fileName.length() + 1];
    strcpy(cstr, fileName.c_str());
    ifstream fout(cstr);
    if (!fout.is_open())
    {
        cout << "Ошибка при открытии файла " << fileName << endl;
        delete [] cstr;
        return false;
    }
    else
    {
        string currentLine;
        for (int i = 0; i < menuCount; i++)
        {

            getline(fout, currentLine);
            *(sa + i) = currentLine;
        }
    }
    fout.close();
    delete [] cstr;
    return true;
}

char menu (string * menuItems, int itemCount)
{   // Реализация меню.
    for (int i = 0; i < itemCount; i++)
    {
        cout << *(menuItems + i) << endl;
    }
    cout << "Выберите выполняемую программу: ";
    char selectedKey;
    cin >> selectedKey;
    return toupper(selectedKey);
}

void changeDimensions(int &row, int &column)
{   // Смена размеров матрицы
    cout << "Текущее количество строк: " << row << endl;
    cout << "Текущее количество столбцов: " << column << endl;
    cout << "Количество строк: ";
    cin >> row;
    cout << "Количество столбцов: ";
    cin >> column;
}

qreal randBetween (int a, int b)
{	// Генерация случайного плавающего числа в отрезке [a, b]
    qreal result = 0;
    result = (int)(((qreal)rand()) / RAND_MAX * (b - a) + a) +
            (int)(((qreal)rand()) / RAND_MAX * 100) / 100.0;
    return result;
}

void fillMatrixRandom (qreal *V, int rows, int columns, int a, int b)
{   // Заполнение матрицы случайными числами
    for (int i = 0; i < rows * columns; i++)
    {
        *(V + i) = randBetween(a, b);
    }
}

void printMatrix(qreal *V, int rows, int columns)
{   // Печать матрицы на экран
    for (int i = 0; i < rows * columns; i++)
    {
        cout << setw(5) << *(V + i);
        if ((i + 1) % (columns)) cout << " ";
        else cout << endl;
    }
}

void copyMatrix(qreal *rec, qreal *source, int row, int column, int sourceColumn)
{   // Загрузка содержимого матрицы source в матрицу rec
    int sourceShift = -1;
    for (int i = 0; i < row * column; i++)
    {
        if (i % column == 0 && i != 0) sourceShift += sourceColumn - column + 1;
        else sourceShift++;
        *(rec + i) = *(source + sourceShift);
    }
}

void linearCopyMatrix (qreal *rec, qreal *source, int rows, int columns)
{   // Линейное копирование элементов массива
    for (int i = 0; i < rows * columns; i++)
        *(rec + i) = *(source + i);
}

qreal getME(qreal *V, int row, int column, int tCol)
{   // Получение двумерного элемента из одномерного массива
    return *(V + (row - 1) * tCol + column - 1);
}

void setME(qreal *V, int row, int column, int tCol, qreal someValue)
{   // Присваивание некоторого значения элементу двумерного массива из плоского массива
    *(V + (row - 1) * tCol + column - 1) = someValue;
}

void loadMatrixKeyboard(qreal *V, int rows, int columns)
{   // Ввод значений матрицы с клавиатуры
    qreal someVal;
    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= columns; j++)
        {
            cout << "[" << i <<"][" << j << "]: ";
            cin >> someVal;
            setME(V, i, j, columns, someVal);
        }
}

bool saveMatrix (string fileName, qreal * V, int rows, int columns)
{   // Сохранение элементов массива в файл
    char *cstr = new char[fileName.length() + 1];
    strcpy(cstr, fileName.c_str());
    ofstream fout(cstr);
    if (!fout.is_open())
    {
        cout << "Ошибка при открытии файла " << fileName << endl;
        delete [] cstr;
        return false;
    }
    else
    {
        fout << rows << endl;
        fout << columns << endl;
        for (int i = 1; i <= rows; i++)
            for (int j = 1; j <= columns; j++)
                fout << getME(V, i, j, columns) << endl;
    }
    fout.close();
    delete [] cstr;
    return true;
}

bool loadMatrixFile (string fileName, qreal * V, int &rows, int &columns)
{   // Загрузка элементов массива из файла
    char *cstr = new char[fileName.length() + 1];
    strcpy(cstr, fileName.c_str());
    ifstream fin(cstr);
    if (!fin.is_open())
    {
        cout << "Ошибка при открытии файла " << fileName << endl;
        delete [] cstr;
        return false;
    }
    else
    {
        fin >> rows;
        fin >> columns;
        qreal someVal;
        for (int i = 1; i <= rows; i++)
            for (int j = 1; j <= columns; j++)
            {
                fin >> someVal;
                setME(V, i, j, columns, someVal);
            }
    }
    fin.close();
    delete [] cstr;
    return true;
}

qreal rowMaxNorm(qreal *V, int rows, int columns)
{   // Определение максимальной нормы строк матрицы
    qreal maxNorm = rowNorm (V, 1, columns);
    qreal currentNorm;
    for (int i = 2; i <= rows; i++)
    {
        currentNorm = rowNorm(V, i, columns);
        if (maxNorm < currentNorm) maxNorm = currentNorm;
    }
    return maxNorm;
}

qreal rowNorm(qreal *V, int row, int columns)
{   // Подсчёт нормы строки матрицы
    qreal norm = 0;
    for (int i = 1; i <= columns; i++)
        norm += fabs(getME(V, row, i, columns));
    return norm;
}

qreal columnMaxNorm(qreal *V, int rows, int columns)
{   // Нахождение максимальной нормы столбцов матрицы
    qreal maxNorm = columnNorm (V, rows, 1, columns);
    qreal currentNorm;
    for (int i = 2; i <= columns; i++)
    {
        currentNorm = columnNorm (V, rows, i, columns);
        if (maxNorm < currentNorm)
            maxNorm = currentNorm;
    }
    return maxNorm;
}

qreal columnNorm (qreal *V, int rows, int column, int columns)
{   // Подсчёт нормы столбца
    qreal norm = 0;
    for (int i = 1; i <= rows; i++)
        norm += fabs(getME(V, i, column, columns));
    return norm;
}

qreal sumSqrt (qreal *V, int rows, int columns)
{   // Вычисление квадратного корня суммы квадратов элементов
    qreal squareSum = 0;
    for (int i = 0; i < rows * columns; i++)
        squareSum += *(V + i) * *(V + i);
    return sqrt(squareSum);
}

int minME (qreal *V, int rows, int columns, int &indexC)
{   // Нахождение индексов наименьшего элемента массива
    int r = 1, c = 1;
    qreal current, minE = getME(V, 1, 1, columns);
    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= columns; j++)
        {
            current = getME(V, i, j, columns);
            if (current < minE)
            {
                minE = current;
                r = i;
                c = j;
            }
        }
    indexC = c;
    return r;
}

int maxME (qreal *V, int rows, int columns, int &indexC)
{   // Нахождение индексов наименьшего элемента массива
    int r = 1, c = 1;
    qreal current, maxE = getME(V, 1, 1, columns);
    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= columns; j++)
        {
            current = getME(V, i, j, columns);
            if (current > maxE)
            {
                maxE = current;
                r = i;
                c = j;
            }
        }
    indexC = c;
    return r;
}

void replaceRow(qreal *V, int row, int columns)
{   // Перестановка элементов строки
    qreal temp;
    for (int i = 1; i < columns - i + 1; i++)
    {
        temp = getME(V, row, i, columns);
        setME(V, row, i, columns, getME(V, row, columns - i + 1, columns));
        setME(V, row, columns - i + 1, columns, temp);
    }
}

void sortMatrixByColumn(qreal *V, int rows, int columns, int columnNumber, bool descendP)
{   // Реализация сортировки по некоторому столбцу
    qreal rowIndex;
    for (int i = 1; i <= columns; i++)
    {
        rowIndex = selectRowInColumn (V, i, rows, columnNumber, columns, descendP);
        if (i != rowIndex) changeRows (V, i, rowIndex, columns);
    }
}

int selectRowInColumn(qreal *V, int startRow, int totalRows, int columnNumber, int totalColumns, bool descendP)
{   // Выбор некоторой строки
    int index = startRow;
    for (int i = startRow + 1; i <= totalRows; i++)
    {
        bool decition;
        if (descendP) decition =
                getME(V, index, columnNumber, totalColumns) < getME(V, i, columnNumber, totalColumns);
        else decition =
                getME(V, index, columnNumber, totalColumns) > getME(V, i, columnNumber, totalColumns);
        if (decition) index = i;

    }
    return index;
}

void changeRows (qreal *V, int firstRow, int secondRow, int totalColumns)
{   // Перестановка строк
    qreal temp;
    for (int i = 1; i <= totalColumns; i++)
    {
        temp = getME(V, firstRow, i, totalColumns);
        setME(V, firstRow, i, totalColumns, getME(V, secondRow, i, totalColumns));
        setME(V, secondRow, i, totalColumns, temp);
    }
}

void inverseMatrixRows (qreal *V, int rows, int columns)
{
    qreal temp;
    for (int i = 1; i <= rows; i++)
        for (int j = 1; j < columns - j + 1; j++)
        {
            temp = getME(V, i, j, columns);
            setME(V, i, j, columns, getME(V, i, columns - j + 1, columns));
            setME(V, i, columns - j + 1, columns, temp);
        }
}
