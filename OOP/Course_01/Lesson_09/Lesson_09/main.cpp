#include <QCoreApplication>
#include <ctime>
#include <iostream>
#include <cmath>

using namespace std;
void fillRandom (qreal *V, int n)
{
    for (int i = 0; i < n; ++i)
    {
        V[i] = ((qreal)rand())/RAND_MAX * 100.0;
    }
}

void displayArray (qreal *V, int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout<<i<<" element: "<< V[i]<< "\n";
    }

}

qreal scalarProduct(qreal *V, qreal *U, int n)
{
    qreal sum = 0;
    for (int i = 0; i < n; ++i)
        sum += V[i] * U[i];
    return sum;
}

qreal vLength (qreal *V, int n)
{
    qreal sumProduct = 0;
    for (int i = 0; i<n; ++i)
        sumProduct += V[i] * V[i];
    sumProduct = sqrt(sumProduct);
    return sumProduct;
}

int minItemProduct (qreal *V, qreal *U, int n)
{
    int m = 0;
    V[0] *= U[n - 1];
    for (int i = 1; i < n; ++i)
    {
        V[i] *= U[n - i - 1];
        if (V[m] > V[i]) m = i;
    }
    return m;
}

qreal areaTriangle (qreal *x, qreal *y)
{
    return abs(((x[1] - x[0]) * (y[2] - y[0]) - (x[2] - x[0]) * (y[1] - y[0])) / 2);
}

void coefSumPolynoms (qreal *U, qreal *V, qreal *W, int m, int n)
{
    int i = 0;
    while (i <= m && i <= m)
    {
        W[i] = U[i] + V[i];
        ++i;
    }
    while (i <= m)
    {
        W[i] = U[i];
        ++i;
    }
    while (i <= n)
    {
        W[i] = V[i];
        ++i;
    }

}

void fillWithZeros (qreal *V, int n)
{
    for (int i = 0; i < n; ++i)
    {
        V[i] = 0;
    }
}

void coordCenterSystem(qreal *x, qreal *y, qreal *m, int n, qreal &xs, qreal &ys)
{
    qreal ms = 0;
    xs = 0, ys = 0;
    for (int i = 0; i < n; ++i)
    {
        ms += m[i];
        xs += x[i] * m[i];
        ys += y[i] * m[i];
    }
    xs /= ms;
    ys /= ms;
}

void insertSpace (char *s, char *t)
{   // Вставка пробелов между элементами массива s.
    int i = 0;
    while (s[i] != '\0')
    {
        int k = 2 * i;
        t[k] = s[i];
        t[k + 1] = ' ';
        ++i;
    }
}


int main(int argc, char *argv[])
{
    srand(time(0));
    QCoreApplication a(argc, argv);
    int N = 10;
    qreal myArray[N];
    qreal myNewArray[N];
    qreal myWArray [N];
    fillRandom(myArray, N);
    fillRandom(myNewArray, N);
    fillWithZeros(myWArray, N);
    cout<<"myArray:\n";
    displayArray(myArray, N);
    cout<<"myNewArray:\n";
    displayArray(myNewArray, N);
    cout<<"Scalar product: "<<scalarProduct(myArray, myNewArray, N)<<"\n";
    cout<<"Array length: "<<vLength(myArray, N)<<"\n";

    cout<<"Minimal production: "<<minItemProduct(myArray, myNewArray, N)<<"\n";
    cout<<"myArray:\n";
    displayArray(myArray, N);
    fillRandom(myArray, N);
    fillRandom(myNewArray, N);
    cout<<"myArray:\n";
    displayArray(myArray, N);
    cout<<"myNewArray:\n";
    displayArray(myNewArray, N);
    cout<<"Triangle square: "<< areaTriangle(myArray, myNewArray)<<"\n";
    coefSumPolynoms(myArray, myNewArray, myWArray, 5, 6);
    cout<<"Coefficients in myWArray:\n";
    displayArray(myWArray, N);
    cout << "Вычисление центра масс."<<endl;
    fillRandom(myArray, N);
    fillRandom(myNewArray, N);
    fillRandom(myWArray, N);
    cout<<"myArray:\n";
    displayArray(myArray, N);
    cout<<"myNewArray:\n";
    displayArray(myNewArray, N);
    cout<<"myWArray:\n";
    displayArray(myWArray, N);

    qreal xc, yc;
    coordCenterSystem(myArray, myNewArray, myWArray, N, xc, yc);
    cout << "xs = " << xc << endl;
    cout << "ys = " << yc << endl;
    char cA[] = {"abcdef"};
    char cB[11];
    insertSpace (cA, cB);
    for (int i = 0; i < 11; ++i)
        cout<<cB[i]<<endl;
    return 0;
}
