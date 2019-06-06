#include <QCoreApplication>
#include <iostream>
#include <math.h>

// Neuron class.
class Neuron {
    double * weights ;
    double * sources ;
    int count;

    // sigmoid function
    double sigmoid (double x) {
        return 1 / (1 + std::exp (-x));
    }

public:
    // Constructor
    Neuron () {}
    Neuron (int n, double * srcs) {
        count = n ;
        weights = new double [count] ;
        sources = srcs ;
        for (int i = 0 ; i < count ; i++) {
            weights [i] = (double) rand() / RAND_MAX * 2 - 1 ;
        }
    }

    // change settings
    void edit (int n, double * srcs) {
        count = n ;
        weights = new double [count] ;
        sources = srcs ;
        for (int i = 0 ; i < count ; i++) {
            weights [i] = (double) rand() / RAND_MAX * 2 - 1 ;
        }
    }

    // Calculation by neuron
    double eval () {
        double result = 0 ;
        for (int i = 0 ; i < count ; i++)
            result += weights [i] * sources [i] ;
        return sigmoid (result) ;
    }

    // Destructor
    ~Neuron () {
        delete [] weights ;
        delete [] sources ;
    }
};

// Neural tier class
class Tier {
    double * inData ;

    int inCount, outCount ;
    Neuron * neurs ;
public:
    double * outData ;

    // Class constructor
    Tier () {}

    Tier (int in, int out, double * inpDatas) {
        inCount = in ;
        outCount = out ;
        inData = inpDatas ;
        //outData = outDatas ;
        outData = new double [outCount] ;
        neurs = new Neuron [outCount];
        for (int i = 0 ; i < outCount ; i++) {
            neurs [i].edit (inCount, inData);
            outData [i] = 0 ;
        }
    }

    // Evaluate tier values
    void eval () {
        for (int i = 0 ; i < outCount ; i++)
            outData [i] = neurs [i].eval() ;
    }

    void edit (int in, int out, double * inpDatas) {
        inCount = in ;
        outCount = out ;
        inData = inpDatas ;
        //outData = outDatas ;
        outData = new double [outCount] ;
        neurs = new Neuron [outCount];
        for (int i = 0 ; i < outCount ; i++) {
            neurs [i].edit (inCount, inData);
            outData [i] = 0 ;
        }
    }
};

class NeuralNetwork {
    Tier * tiers ;
    int layersCount ;
    int layerWidth ;
    double * source ;
    int sourcesCount ;
public:
    NeuralNetwork () {}

    // Make neural network with "count" layers and
    // "width" plus one output layer with width = 1.
    NeuralNetwork (int count, int width, int srcs, double * src) {
        layersCount = count ;
        layerWidth = width ;
        tiers = new Tier [layersCount + 1] ;
        sourcesCount = srcs ;
        source = src ;
        tiers [0].edit (sourcesCount, layerWidth, source) ;
        for (int i = 1 ; i < layersCount ; i++)
            tiers [i].edit (layerWidth, layerWidth, tiers [i - 1].outData) ;
        tiers [layersCount].edit (layerWidth, 1, tiers [layerWidth].outData) ;
    }

    void edit (int count, int width, int srcs, double * src) {
        layersCount = count ;
        layerWidth = width ;
        tiers = new Tier [layersCount + 1] ;
        sourcesCount = srcs ;
        source = src ;
        tiers [0].edit (sourcesCount, layerWidth, source) ;
        for (int i = 1 ; i < layersCount ; i++)
            tiers [i].edit (layerWidth, layerWidth, tiers [i - 1].outData) ;
        tiers [layersCount].edit (layerWidth, 1, tiers [layerWidth].outData) ;
    }

    double * eval () {
    for (int i = 0 ; i < layersCount + 1 ; i++)
        tiers [i].eval();
    return tiers [layersCount].outData ;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //std::cout << "Hello, World!" << std::endl ;
    srand(time(NULL)) ;
    double source [10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1} ;
    NeuralNetwork * myNetwork = new NeuralNetwork (10, 2, 10, source) ;
    double * result = myNetwork->eval() ;
    std::cout << result [0] << std::endl ;
    return a.exec();
}
