#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout* myLayout = new QGridLayout;

    signalMapper = new QSignalMapper(this);
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
        {
            buttonsArray[i][j] = new QPushButton(" ");
            connect(buttonsArray[i][j], SIGNAL(clicked()), signalMapper, SLOT(map()));
            signalMapper->setMapping(buttonsArray[i][j], i*10+j);
            myLayout->addWidget(buttonsArray[i][j], i, j);
            field[i][j] = 0;
        }
    //myLayout->addWidget(buttonsArray[0][0], 0, 0);
    connect(signalMapper, SIGNAL(mapped(int)),
            this, SLOT(catchSignal(int)));
    winLength = 5;
    this->setLayout(myLayout);
}

Widget::~Widget()
{

}

void Widget::catchSignal(int id)
{
    int i,j;
    i = id/10;
    j = id%10;
    buttonsArray[i][j]->setText("X");
    field[i][j] = 1;
    if (isWinX())
    {
        QMessageBox msgBox;
        msgBox.setText("X wins!");
        msgBox.exec();
        resetButtons();
    }
    else
    {
    int zeroMove = bestMove();
    i = zeroMove/10;
    j = zeroMove%10;
    buttonsArray[i][j]->setText("O");
    field[i][j] = 2;
    }
    if (isWinO())
    {
        QMessageBox msgBox;
        msgBox.setText("O wins!");
        msgBox.exec();
        resetButtons();
    }
}

bool Widget::isWinO()
{
    return isWin(2, winLength);
}

bool Widget::isWinX()
{
    return isWin(1, winLength);
}

void Widget::resetButtons()
{
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
        {
            buttonsArray[i][j]->setText(" ");
            field[i][j] = 0;
        }
}

bool Widget::isWin(int num, int winLen)
{
    bool win = false;

    for (int i=0; i<10 && !win; i++)
        for (int j=0; j<11-winLen && !win; j++)
            if (rateHoriz(i,j,num) == winLen) win = true;

    for (int i=0; i<11-winLen && !win; i++)
        for (int j=0; j<10 && !win; j++)
            if (rateVert(i,j,num) == winLen) win = true;

    for (int i=0; i<11-winLen && !win; i++)
        for (int j=0; j<11-winLen && !win; j++)
            if (rateDiagOne(i,j,num) == winLen) win = true;

    for (int i=0; i<11-winLen && !win; i++)
        for (int j=winLen-1; j<10; j++)
            if (rateDiagTwo(i,j,num) == winLen) win = true;

    return win;
}

int Widget::bestMove()
{
    return bestMoveDepth(2);
}

int Widget::bestMoveDepth(int depth)
{
    int bMove;
    int cost = 100;
    int currentCost;
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
            if (field[i][j] == 0)
            {
                field[i][j] = 2;
                currentCost = ratingOfPosition(depth-1, true);
                if (currentCost<cost)
                {
                    cost = currentCost;
                    bMove = i*10 + j;
                }
                field[i][j] = 0;
            }
    return bMove;
}

int Widget::ratingOfPosition(int depth, bool isMax)
{
    if (depth == 0) return ratingPosition();
    int cost;
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
            if(field[i][j]==0)
            {
                if (isMax) field[i][j] = 1;
                else field[i][j] = 2;
                if (i==0 && j==0) cost = ratingOfPosition(depth-1, !isMax);
                else
                {
                    if (isMax)
                    {if (cost<ratingOfPosition(depth-1, !isMax))
                            cost=ratingOfPosition(depth-1, !isMax);}
                    else if (cost>ratingOfPosition(depth-1, !isMax))
                        cost=ratingOfPosition(depth-1, !isMax);
                }
                field[i][j] = 0;
            }
    return cost;
}

int Widget::ratingPosition()
{
    int result = 0;
    for (int i=0; i<10; i++)
        for (int j=0; j<11-winLength; j++)
            result += rateHoriz(i,j, 1);

    for (int i=0; i<11-winLength; i++)
        for (int j=0; j<10; j++)
            result += rateVert(i,j, 1);

    for (int i=0; i<11-winLength; i++)
        for (int j=0; j<11-winLength; j++)
            result += rateDiagOne(i,j, 1);

    for (int i=0; i<11-winLength; i++)
        for (int j=winLength-1; j<10; j++)
            result += rateDiagTwo(i,j, 1);
    return result;
}

int Widget::rateHoriz(int x, int y, int num)
{
    return rate(x, y, 0, 1, num);
}

int Widget::rateVert(int x, int y, int num)
{
    return rate(x, y, 1, 0, num);
}

int Widget::rateDiagOne(int x, int y, int num)
{
    return rate(x, y, 1, 1, num);
}

int Widget::rateDiagTwo(int x, int y, int num)
{
    return rate(x, y, 1, -1, num);
}

int Widget::rate(int x, int y, int xm, int ym, int num)
{
    int result = 0;
    bool isOppSymb = false;
    int cS;
    for (int i=0; i<winLength && !isOppSymb; i++)
    {
        cS = field[x+i*xm][y+i*ym];
        if (cS != 0 && cS != num)
        {
            isOppSymb = true;
            result = 0;
        }
        else
            if (cS == num)
            {
                //if (result>0) result--;
                //else result++;
                result++;
            }
    }
    return result;
}
