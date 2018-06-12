#include <QCoreApplication>
#include <QtCore>
#include <iostream>
#include <time.h>

const qreal mutProb = 0.3;

void solveSystem(qreal system[4][3])
{
    qreal delta = system[0][0]*system[1][1]*system[2][2] +
            system[1][0]*system[2][1]*system[0][2] +
            system[0][1]*system[1][2]*system[2][0] -
            system[2][0]*system[1][1]*system[0][2] -
            system[1][0]*system[0][1]*system[2][2] -
            system[0][0]*system[1][2]*system[2][1];
    //std::cout << "delta = " << delta << "\n";
    qreal delta1 = system[3][0]*system[1][1]*system[2][2] +
            system[1][0]*system[2][1]*system[3][2] +
            system[3][1]*system[1][2]*system[2][0] -
            system[2][0]*system[1][1]*system[3][2] -
            system[1][0]*system[3][1]*system[2][2] -
            system[3][0]*system[1][2]*system[2][1];
    //std::cout << "[3][9] = " << system[3][0] << "\n";
    //std::cout << "delta1 = " << delta1 << "\n";
    qreal delta2 = system[0][0]*system[3][1]*system[2][2] +
            system[3][0]*system[2][1]*system[0][2] +
            system[0][1]*system[3][2]*system[2][0] -
            system[2][0]*system[3][1]*system[0][2] -
            system[3][0]*system[0][1]*system[2][2] -
            system[0][0]*system[3][2]*system[2][1];
    qreal delta3 = system[0][0]*system[1][1]*system[3][2] +
            system[1][0]*system[3][1]*system[0][2] +
            system[0][1]*system[1][2]*system[3][0] -
            system[3][0]*system[1][1]*system[0][2] -
            system[1][0]*system[0][1]*system[3][2] -
            system[0][0]*system[1][2]*system[3][1];
    system[3][0] = delta1 / delta;
    system[3][1] = delta2 / delta;
    system[3][2] = delta3 / delta;
}

qreal fitness (qreal x1, qreal x2, qreal x3, qreal x4, qreal x5, qreal x6)
{
    return 0*x1 + x2 - 3*x3 + 0*x4 + 2*x5 + 0*x6;
}

qreal getValue(qreal max, qreal min)
{
    return rand() * (max - min) / RAND_MAX + min;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qreal sstm[4][3];
    sstm[0][0] = 1;
    sstm[1][0] = 3;
    sstm[2][0] = -1;
    sstm[3][0] = 0;
    sstm[0][1] = 0;
    sstm[1][1] = -2;
    sstm[2][1] = 4;
    sstm[3][1] = 0;
    sstm[0][2] = 0;
    sstm[1][2] = -4;
    sstm[2][2] = 3;
    sstm[3][2] = 0;

    qreal rndStuffCoef[4][3];
    rndStuffCoef[0][0] = 0;
    rndStuffCoef[1][0] = 2;
    rndStuffCoef[2][0] = 0;
    rndStuffCoef[3][0] = 7;
    rndStuffCoef[0][1] = 1;
    rndStuffCoef[1][1] = 0;
    rndStuffCoef[2][1] = 0;
    rndStuffCoef[3][1] = 12;
    rndStuffCoef[0][2] = 0;
    rndStuffCoef[1][2] = 8;
    rndStuffCoef[2][2] = 1;
    rndStuffCoef[3][2] = 10;

    qreal populations[100][6];
    //    populations[0][0] = 0; // x4
    //    populations[0][1] = 0; // x5
    //    populations[0][2] = 11; // x6
    srand(time(NULL));

    for(int i = 0; i < 100; i++)
    {
makeValues:
        populations[i][0] = getValue(0, 10);
        populations[i][1] = getValue(0, 10);
        populations[i][2] = getValue(0, 10);
        sstm[3][0] = rndStuffCoef[3][0] -
                rndStuffCoef[2][0] * populations[i][2] -
                rndStuffCoef[1][0] * populations[i][1] -
                rndStuffCoef[0][0] * populations[i][0];
        sstm[3][1] = rndStuffCoef[3][1] -
                rndStuffCoef[2][1] * populations[i][2] -
                rndStuffCoef[1][1] * populations[i][1] -
                rndStuffCoef[0][1] * populations[i][0];
        sstm[3][2] = rndStuffCoef[3][2] -
                rndStuffCoef[2][2] * populations[i][2] -
                rndStuffCoef[1][2] * populations[i][1] -
                rndStuffCoef[0][2] * populations[i][0];
        solveSystem(sstm);
        populations[i][3] = sstm[3][0]; // x1
        populations[i][4] = sstm[3][1]; // x2
        populations[i][5] = sstm[3][2]; // x3
        if (populations[i][3] < 0 ||
                populations[i][4] < 0 ||
                populations[i][5] < 0)
            goto makeValues;
    }
    int bestPopulationIndex = -1;
    int worstPopulationIndex = -1;
    for (int i = 1; i < 100; i++)
    {
        if (populations[i][0] >= 0 &&
                populations[i][1] >= 0 &&
                populations[i][2] >= 0 &&
                populations[i][3] >= 0 &&
                populations[i][4] >= 0 &&
                populations[i][5] >= 0)
            if (bestPopulationIndex == -1 ||
                    fitness(populations[i][3], populations[i][4],
                            populations[i][5], populations[i][0],
                            populations[i][1], populations[i][2]) <
                    fitness(populations[bestPopulationIndex][3],
                            populations[bestPopulationIndex][4],
                            populations[bestPopulationIndex][5],
                            populations[bestPopulationIndex][0],
                            populations[bestPopulationIndex][1],
                            populations[bestPopulationIndex][2]))
                bestPopulationIndex = i;
        if (worstPopulationIndex == -1 ||
                fitness(populations[i][3], populations[i][4],
                        populations[i][5], populations[i][0],
                        populations[i][1], populations[i][2]) >
                fitness(populations[worstPopulationIndex][3],
                        populations[worstPopulationIndex][4],
                        populations[worstPopulationIndex][5],
                        populations[worstPopulationIndex][0],
                        populations[worstPopulationIndex][1],
                        populations[worstPopulationIndex][2]))
            worstPopulationIndex = i;
    }

    // цикл улучшения членов популяции
    for (int i = 1; i < 1000; i++)
    {
        int species1 = rand()%100;
        int species2 = rand()%100;
        qreal x1, x2, x3, x4, x5, x6;
        x4 = (populations[species1][0] +
                populations[species2][0]) / 2;
        x5 = (populations[species1][1] +
                populations[species2][1]) / 2;
        x6 = (populations[species1][2] +
                populations[species2][2]) / 2;
        x4 += (rand()*1.0/RAND_MAX > mutProb ? getValue(-1, 1):0);
        x5 += (rand()*1.0/RAND_MAX > mutProb ? getValue(-1, 1):0);
        x6 += (rand()*1.0/RAND_MAX > mutProb ? getValue(-1, 1):0);

        x4 *= (x4 < 0 ? 0:1);
        x5 *= (x5 < 0 ? 0:1);
        x6 *= (x6 < 0 ? 0:1);

        sstm[3][0] = rndStuffCoef[3][0] -
                rndStuffCoef[2][0] * x6 -
                rndStuffCoef[1][0] * x5 -
                rndStuffCoef[0][0] * x4;
        sstm[3][1] = rndStuffCoef[3][1] -
                rndStuffCoef[2][1] * x6 -
                rndStuffCoef[1][1] * x5 -
                rndStuffCoef[0][1] * x4;
        sstm[3][2] = rndStuffCoef[3][2] -
                rndStuffCoef[2][2] * x6 -
                rndStuffCoef[1][2] * x5 -
                rndStuffCoef[0][2] * x4;
        solveSystem(sstm);
        x1 = sstm[3][0];
        x2 = sstm[3][1];
        x3 = sstm[3][2];
        if (fitness(x1, x2, x3, x4, x5, x6) < fitness(populations[worstPopulationIndex][3],
                                                      populations[worstPopulationIndex][4],
                                                      populations[worstPopulationIndex][5],
                                                      populations[worstPopulationIndex][0],
                                                      populations[worstPopulationIndex][1],
                                                      populations[worstPopulationIndex][2]))
        {
            populations[worstPopulationIndex][3] = x1;
            populations[worstPopulationIndex][4] = x2;
            populations[worstPopulationIndex][5] = x3;
            populations[worstPopulationIndex][0] = x4;
            populations[worstPopulationIndex][1] = x5;
            populations[worstPopulationIndex][2] = x6;
            for (int i = 1; i < 100; i++)
            {
                if (populations[i][0] >= 0 &&
                        populations[i][1] >= 0 &&
                        populations[i][2] >= 0 &&
                        populations[i][3] >= 0 &&
                        populations[i][4] >= 0 &&
                        populations[i][5] >= 0)
                {
                    if (bestPopulationIndex == -1 ||
                            fitness(populations[i][3], populations[i][4],
                                    populations[i][5], populations[i][0],
                                    populations[i][1], populations[i][2]) <
                            fitness(populations[bestPopulationIndex][3],
                                    populations[bestPopulationIndex][4],
                                    populations[bestPopulationIndex][5],
                                    populations[bestPopulationIndex][0],
                                    populations[bestPopulationIndex][1],
                                    populations[bestPopulationIndex][2]))
                        bestPopulationIndex = i;
                    if (worstPopulationIndex == -1 ||
                            fitness(populations[i][3], populations[i][4],
                                    populations[i][5], populations[i][0],
                                    populations[i][1], populations[i][2]) >
                            fitness(populations[worstPopulationIndex][3],
                                    populations[worstPopulationIndex][4],
                                    populations[worstPopulationIndex][5],
                                    populations[worstPopulationIndex][0],
                                    populations[worstPopulationIndex][1],
                                    populations[worstPopulationIndex][2]))
                        worstPopulationIndex = i;
                }
            }
        }
    }
    std::cout << "id = " << bestPopulationIndex << "\n";
    std::cout << "x1 = " << populations[bestPopulationIndex][3] << "\n";
    std::cout << "x2 = " << populations[bestPopulationIndex][4] << "\n";
    std::cout << "x3 = " << populations[bestPopulationIndex][5] << "\n";
    std::cout << "x4 = " << populations[bestPopulationIndex][0] << "\n";
    std::cout << "x5 = " << populations[bestPopulationIndex][1] << "\n";
    std::cout << "x6 = " << populations[bestPopulationIndex][2] << "\n";
    std::cout << "fitness = " << fitness(populations[bestPopulationIndex][3],
            populations[bestPopulationIndex][4],
            populations[bestPopulationIndex][5],
            populations[bestPopulationIndex][0],
            populations[bestPopulationIndex][1],
            populations[bestPopulationIndex][2]) << "\n";

    std::cout << "id = " << worstPopulationIndex << "\n";
    std::cout << "x1 = " << populations[worstPopulationIndex][3] << "\n";
    std::cout << "x2 = " << populations[worstPopulationIndex][4] << "\n";
    std::cout << "x3 = " << populations[worstPopulationIndex][5] << "\n";
    std::cout << "x4 = " << populations[worstPopulationIndex][0] << "\n";
    std::cout << "x5 = " << populations[worstPopulationIndex][1] << "\n";
    std::cout << "x6 = " << populations[worstPopulationIndex][2] << "\n";
    std::cout << "fitness = " <<
                 fitness(populations[worstPopulationIndex][3],
            populations[worstPopulationIndex][4],
            populations[worstPopulationIndex][5],
            populations[worstPopulationIndex][0],
            populations[worstPopulationIndex][1],
            populations[worstPopulationIndex][2]) << "\n";
    return a.exec();
}
