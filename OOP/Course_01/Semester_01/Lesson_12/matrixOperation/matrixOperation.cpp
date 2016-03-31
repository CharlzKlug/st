#include "matrixOperation.h"

char selectMenu(string *V, int count)
{   // Выбор меню
    for (int i = 0; i < count; ++i)
        cout << V[i] << endl;
    char pressedButton;
    cin >> pressedButton;
    return toupper(pressedButton);
}

void loadMatrix(TMatr original, TMatr test, int RC, int CC)
{   // Загрузка тестовой матрицы
    for (int i = 0; i < RC; ++i)
        for (int j = 0; j < CC; ++j)
            original[i][j] = test[i][j];
}

void printMatrix(TMatr matrix, int RC, int CC)
{   // Печать матрицы
    for (int i = 0; i < RC; ++i)
        for (int j = 0; j < CC; ++j)
        {
            cout << setw(5) << matrix[i][j];
            if (j != CC - 1) cout << " ";
            else cout << endl;
        }
}

qreal getRandom(int ac, int bc)
{   // Возвращает случайное число в интервале [ac, bc]
    qreal rn;
    rn = (int)((qreal)rand() / RAND_MAX * (bc - ac)) + ac;
    rn = rn + (int)((qreal)rand() / RAND_MAX * 100) / 100.0;
    return rn;
}

void loadRandomMatrix(TMatr matrix, int RC, int CC, int ac, int bc)
{
    for (int i = 0; i < RC; i++)
        for (int j = 0; j < CC; j++)
            matrix[i][j] = getRandom(ac, bc);
}

void transposeMatrix(TMatr matrix, int RC, int CC)
{   // Транспонирование матрицы
    qreal temp;
    for (int i = 0; i < RC; i++)
        for (int j = i + 1; j < CC; j++)
        {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
        }
}

void sumMatrix(TMatr a, TMatr b, int RC, int CC)
{   // Сложение двух матриц a = a + b
    for (int i = 0; i < RC; i++)
        for (int j = 0; j < CC; j++)
            a[i][j] += b[i][j];
}

void subMatrix(TMatr a, TMatr b, int RC, int CC)
{   // Вычитание двух матриц a = a - b
    for (int i = 0; i < RC; i++)
        for (int j = 0; j < CC; j++)
            a[i][j] -= b[i][j];
}

void mulMatrix(TMatr a, TMatr b, TMatr c, int RC, int CC)
{   // Перемножение двух матриц
    for (int i = 0; i < RC; i++)
        for (int j = 0; j < CC; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < RC; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
}

void makeVectMaxModRow (TVect res, TMatr M, int RC, int CC)
{   // Построение вектора из максимальных значений строк
    for (int i = 0; i < RC; i++)
    {
        res[i] = M[i][0];
        for (int j = 1; j < CC; j++)
        {
            if (fabs(res[i]) < fabs(M[i][j])) res[i] = M[i][j];
        }
    }
}

void printVect(TVect V, int length, bool isColumn)
{   // Печать столбцовые и строчные векторы
    for (int i = 0; i < length; i++)
    {
        cout << V[i];
        if (isColumn) cout << endl;
        else cout << " ";
    }
}

void makeVectMaxModCol (TVect res, TMatr M, int RC, int CC)
{   // Построение вектора из максимальных значений столбцов
    for (int i = 0; i < RC; i++)
    {
        res[i] = M[0][i];
        for (int j = 1; j < CC; j++)
        {
            if (fabs(res[i]) < fabs(M[j][i])) res[i] = M[j][i];
        }
    }
}

qreal diagSum(TMatr M, int RC, int CC, int dn)
{   // Вычисление суммы диагонали
    qreal sum = 0;
    int m = dn < 0 ? - dn : 0;
    int n = dn < 0 ? 0 : dn;
    while (m < RC && n < CC)
    {
        sum += M[m][n];
        m++;
        n++;
    }
    return sum;
}
