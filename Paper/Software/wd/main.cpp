#include <QCoreApplication>
#include <iostream>
#include <math.h>
#include <fstream>
#include <sstream>

// Neuron class.
class Neuron {
    int count;


    double * sources ;

    // sigmoid function
    double sigmoid (double x) {
        return 1 / (1 + std::exp (-x));
    }



public:
    double result = 0 ;
    double delta = 0 ;
    double * deltaWeights ;
    double * weights ;

    // Constructor
    Neuron () {}
    Neuron (int n, double * srcs) {
        edit (n, srcs) ;
    }

    // change settings
    void edit (int n, double * srcs) {
        count = n ;
        weights = new double [count] ;
        deltaWeights = new double [count];
        sources = srcs ;
        for (int i = 0 ; i < count ; i++) {
            weights [i] = static_cast <double> (rand()) / RAND_MAX * 2 - 1 ;
            deltaWeights[i] = 0;
            //std::cout << "  Make " << i << " weight: " << weights [i] << std::endl ;
        }
    }

    // Calculation by neuron
    double eval () {
        double reslt = 0 ;
        for (int i = 0 ; i < count ; i++)
            reslt += weights [i] * sources [i] ;
        result = sigmoid (reslt) ;
        return result ;
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

    double * deltaW ;
public:
    double * outData ;
    Neuron * neurs ;

    void changeSource (double * src) {
        inData = src;
    }

    void lastCorrectWeights (double learnConstant, double moment) {
        for (int i = 0; i < outCount; i++) {
            for (int j = 0; j < inCount; j++) {
                neurs[i].deltaWeights[j] = learnConstant * neurs[i].delta * inData [j] + moment * neurs[i].deltaWeights[j];
                neurs[i].weights[j] += neurs[i].deltaWeights[j];
                //std::cout << "Neur [" << i << "], weight[" << j << "] =" << neurs[i].weights[j] << std::endl;
            }
        }

    }

    // Calculate delta for outer tier.
    void deltaOuter (double idealResult) {
        //std::cout << "Neur result: " << neurs[0].result << std::endl ;
        //std::cout << "Out result: " << outData [0] << std::endl ;
        neurs[0].delta = (idealResult - neurs[0].result) * (1 - neurs[0].result) * (neurs[0].result) ;
        //std::cout << "Delta Outer : " << neurs[0].delta << std::endl;
    }

    // Calculate delta for inner tier.
    void deltaInner (Tier * innerTier) {
        double sum;
        for (int i = 0; i < inCount; i++) {
            sum = 0;
            for (int j = 0; j < outCount; j++)
                sum += (neurs[j].weights[i] * neurs[j].delta);
            innerTier->neurs[i].delta = (1 - innerTier->neurs[i].result) * innerTier->neurs[i].result * sum ;
            //std::cout << "Inner delta: " << innerTier->neurs[i].delta << std::endl ;
        }
    }

    void correctWeights (Tier * innerTier, double learnConstant, double moment) {
        for (int i = 0; i < outCount; i++) {
            for (int j = 0; j < inCount; j++) {
                neurs[i].deltaWeights[j] = learnConstant * neurs[i].delta * innerTier->neurs[j].result + moment * neurs[i].deltaWeights[j];
                neurs[i].weights[j] += neurs[i].deltaWeights[j];
                //std::cout << "Neur [" << i << "], weight[" << j << "] =" << neurs[i].weights[j] << std::endl;
            }
        }
    }
    // Class constructor
    Tier () {}

    Tier (int in, int out, double * inpDatas) {
        edit (in, out, inpDatas) ;
    }

    // Evaluate tier values
    void eval () {
        for (int i = 0 ; i < outCount ; i++)
            outData [i] = neurs [i].eval() ;
    }

    // Change a tier settings
    void edit (int in, int out, double * inpDatas) {
        inCount = in ;
        outCount = out ;
        inData = inpDatas ;
        //outData = outDatas ;
        outData = new double [outCount] ;
        neurs = new Neuron [outCount];
        deltaW = new double [outCount] ;
        for (int i = 0 ; i < outCount ; i++) {
            //std::cout << " Make " << i << " neur" << std::endl ;
            neurs [i].edit (inCount, inData);
            outData [i] = 0 ;
        }
    }
};

class NeuralNetwork {
    int layersCount ;
    int layerWidth ;
    int sourcesCount ;
    double * source ;
    double learningCoeff = 0.7 ; // a neuron learning coefficient
    double moment = 0.3 ; // an inertion moment
    Tier * tiers ;

public:

    // Neural network learning
    void learn (double idealResult) {
        tiers [layersCount].deltaOuter(idealResult) ;
        //std::cout << "Calculating tier " << layersCount << " inner deltas" << std::endl;
        //for (int i = layersCount ; i > 0; i++) {
        //tiers [layersCount].deltaInner(& tiers [layersCount - 1]);
        //tiers [layersCount].correctWeights(& tiers[layersCount - 1], learningCoeff, moment);
        //}
        for (int i = layersCount; i > 0; i--) {
            tiers [i].deltaInner(& tiers [i - 1]);
            tiers [i].correctWeights(& tiers[i - 1], learningCoeff, moment);
        }
        //std::cout << "Calculating tier " << layersCount << " weights" << std::endl;

        tiers [0].lastCorrectWeights(learningCoeff, moment) ;
        //        tiers [layersCount].neurs[0].delta = 4 ;
        //tiers [layersCount].neurs[0].delta = idealResult - tiers [layersCount].neurs[0].result ;
        //learningCoeff -= learningCoeff * 0.05;
        //moment -= moment * 0.02;
    }

    NeuralNetwork () {}

    // Make neural network with "count" layers and
    // "width" plus one output layer with width = 1.
    NeuralNetwork (int count, int width, int srcs, double * src) {
        edit (count, width, srcs, src) ;
    }

    // Customize Neural Network settings
    void edit (int count, int width, int srcs, double * src) {
        layersCount = count ;
        layerWidth = width ;
        tiers = new Tier [layersCount + 1] ;
        sourcesCount = srcs ;
        source = src ;

        //std::cout << "Make 0 tier" << std::endl ;
        tiers [0].edit (sourcesCount, layerWidth, source) ;

        for (int i = 1 ; i < layersCount ; i++) {
            //std::cout << "Make " << i << " tier" << std::endl ;
            tiers [i].edit (layerWidth, layerWidth, tiers [i - 1].outData) ;
        }

        //std::cout << "Make " << layersCount << " tier" << std::endl ;
        tiers [layersCount].edit (layerWidth, 1, tiers [layerWidth - 1].outData) ;
    }

    // Change Neural Network source.
    void changeSource (double * src) {
        tiers [0].changeSource(src);
    }

    // Calculate Neural Network value
    double eval () {
        for (int i = 0 ; i < layersCount + 1 ; i++)
            tiers [i].eval();
        return tiers [layersCount].outData[0] ;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //std::cout << "Hello, World!" << std::endl ;
    srand(static_cast <unsigned int> (time(nullptr))) ;
    /*
    double source [1] = {1};
    NeuralNetwork * myNetwork = new NeuralNetwork (1, 1,1,source);
    std::cout << myNetwork->eval() << std::endl;
    for (int i = 0; i < 300; i++){
    myNetwork->learn(0.5);
    std::cout << myNetwork->eval() << std::endl;
    }
    */
    /*
    NeuralNetwork * myNetwork = new NeuralNetwork (10, 10, 10, source) ;
    double * result;
    for (int i = 0; i < 1000; i++) {
        result = myNetwork->eval();
        std::cout<< "Result: " << result [0] * 3 << std::endl;
        myNetwork->learn(0.79) ;

    }
    result = myNetwork->eval();
    std::cout<< "Result: " << result [0] * 3 << std::endl;
*/
    double ** studyCases = new double * [20];
    for (int i = 0; i < 20; i++)
        studyCases [i] = new double [11];

    std::string myString;
    std::ifstream sampleFile ("learnSamples.txt");
    if (sampleFile.is_open()) {
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j<11; j++) {
                getline(sampleFile, myString);
                //std::cout << myString << std::endl;
                std::istringstream(myString) >> studyCases[i][j];
                //std::cout << studyCases[i][j] << std::endl;
            }
        }
        sampleFile.close();
    }

    int index = 0;
    NeuralNetwork * myNetwork = new NeuralNetwork (10, 10, 100, studyCases[index]) ;
    //myNetwork->eval();
    for (int i = 0; i < 5000; i++) {
    std::cout << "Network: " << myNetwork->eval() * 3 << ", actual: " << studyCases[index][10] << std::endl;
        myNetwork->learn(studyCases[index][10] / 3);
        index = static_cast <int> (static_cast<double>(rand()) / RAND_MAX * 19) ;
        myNetwork->changeSource(studyCases[index]);
    }
/*
    for (int i = 0; i < 100; i++) {
        index = static_cast <int> (static_cast<double>(rand()) / RAND_MAX * 19) ;
        myNetwork->changeSource(studyCases[index]);
std::cout << "Network result: " << myNetwork->eval() * 3 << ", actual: " << studyCases[index][10] << std::endl;
    }
*/
    //double result;
    /*
    for (int i = 0; i<4000; i++) {
        //std::cout << "Neur: " << myNetwork->eval();
        //std::cout << ", actual: " << studyCases[index][10] / 3 << std::endl;
        //std::cout << "Index test: " << index << std::endl;
        //for (int j = 0; j < 11; j++)
        //std::cout << studyCases[index][j] << std::endl ;
        //std::cout << "st case:" << studyCases[index][10] / 3 << std::endl;
        myNetwork->learn(studyCases[index][10] / 3);
        index = static_cast <int> (static_cast<double>(rand()) / RAND_MAX * 19) ;
        for (int j=0; j < 11; j++)
            std::cout << studyCases[index][j] << std::endl;
        std::cout << "---" << std::endl;
        myNetwork->changeSource(studyCases[index]);
    }
*/
/*
    std::ifstream myFile ("example.txt");

    double myValue;
    if (myFile.is_open()){
        for (int i = 0; i<10; i++) {
            getline(myFile, myString);
            std::istringstream(myString) >> source[i];
        }
        myNetwork->changeSource(source);
        while (getline(myFile, myString)) {
            std::cout << myNetwork->eval() << ", ";

            std::cout << myString << std::endl;
            for (int i = 1; i<10; i++)
                source[i-1] = source[i];

            std::istringstream(myString) >> source[9];
            //myValue = strtod(myString.c_str(), NULL);
            //std::cout << myValue << std::endl;

        }
        myFile.close();
    }
  */
  return a.exec();
}
