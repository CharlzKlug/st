#include <QCoreApplication>
#include <iostream>

void merge(int * arr, int start, int middle, int end){
    std::cout<<"start="<<start<<" middle="<<middle<<" end="<<end<<std::endl;
    for (int i=0; i<10; i++){
        std::cout<<"["<<i<<"]: "<<arr[i]<<", ";
    }
    std::cout<<std::endl;

    int li=start, ri=middle+1;
    while (ri <= end){
        if (arr[li]>arr[ri]){
            int tmp=arr[ri];
            for (int i=ri; i>li; i--) arr[i]=arr[i-1];
            arr[li]=tmp;
            ri++;
        }
        li++;
        if (li==ri) ri++;
    }
    for (int i=0; i<10; i++){
        std::cout<<"["<<i<<"]: "<<arr[i]<<", ";
    }
    std::cout<<std::endl;
}

void mergeSort (int * arr, int start, int end){
    if (end-start < 2){
        if (arr[start]>arr[end]){
            int tmp=arr[start];
            arr[start]=arr[end];
            arr[end]=tmp;
        }
    } else {
        int middle=(end-start)/2+start;
        mergeSort(arr, start, middle);
        mergeSort(arr, middle+1, end);
        merge(arr, start, middle, end);
    }
}

int rndSt (int h, int l){
    return (rand()*1.0*(h-l)/RAND_MAX)+l;
}

class someClass{
private:
    int* t;
public:
    someClass(int n){
        t = new int[n];
    }
    int * getArray(){
        return t;
    }

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    someClass sc(10);
    int bla[10];

    for (int i=0; i<10; i++){
        sc.getArray()[i]=rndSt(5,-5);
        bla[i]=rndSt(5,-5);
    }

    for (int i=0; i<10; i++){
        std::cout<<"["<<i<<"]: "<<bla[i]<<std::endl;
    }

    //mergeSort(sc.getArray(), 0, 9);
    mergeSort(bla, 0, 9);
    for (int i=0; i<10; i++){
        std::cout<<"["<<i<<"]: "<<bla[i]<<std::endl;
    }

    return 0;
}
