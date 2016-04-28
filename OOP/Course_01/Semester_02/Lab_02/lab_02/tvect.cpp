#include <tvect.h>

TVect::TVect(){
    // Конструктор с количеством элементов
    length = one;
    values = new Mytype[length];
    for (int i = zero; i < length; i++){
        values[i] = zero;
    }
}

TVect::TVect(int n = startLength){
    // Конструктор с количеством элементов
    length = n;
    values = new Mytype[length];
    for (int i = zero; i < n; i++){
        values[i] = zero;
    }
}

TVect::TVect (const TVect & q){
    // Конструктор с копированием
    length = q.length;
    values = new Mytype[length];
    for (int i = 0; i < length; i++){
        values[i] = q.values[i];
    }
}

TVect::TVect (int n, const Mytype * someValues){
    // Конструктор с передаваемым массивом
    length = n;
    values = new Mytype[length];
    for (int i = 0; i < length; i++){
        values[i] = someValues[i];
    }
}

TVect::~TVect(){
    // Деструктор
    delete [] values;
}

bool TVect::saveToFile(std::string fileName){
    // Сохранение сведений в файл
    char * cstr = new char[fileName.length()+1];
    strcpy(cstr, fileName.c_str());
    std::ofstream fout(cstr);
    if (!fout.is_open()){
        delete [] cstr;
        return false;
    } else {
        fout << length << std::endl;
        for (int i=zero; i<length; i++){
            fout<<values[i]<<std::endl;
        }
    }
    fout.close();
    delete [] cstr;
    return true;
}

void TVect::outputToScreen(){
    // Вывод данных на экран
    std::cout<<"Length = "<<length<<std::endl;
    std::cout<<std::setprecision(2);
    for (int i=0; i<length; i++){
        std::cout<<std::fixed<<"["<<i<<"] = "<<std::setw(7)<<values[i]<<std::endl;
    }
}

bool TVect::loadFromFile(std::string fileName){
    // Загрузка данных из файла
    char * cstr = new char[fileName.length()+one];
    strcpy(cstr, fileName.c_str());
    std::ifstream fin(cstr);
    if (!fin.is_open()){
        delete [] cstr;
        return false;
    } else {
        fin>>length;
        delete [] values;
        values=new Mytype[length];
        for (int i=zero; i<length; i++){
            fin>>values[i];
        }
        fin.close();
        delete [] cstr;
        return true;
    }
}

void TVect::addElement(Mytype el){
    // Добавление элемента в конец вектора
    Mytype * temp=new Mytype[length];
    for (int i=zero; i<length; i++){
        temp[i]=values[i];
    }
    delete [] values;
    values = new Mytype[length+one];
    for (int i=zero; i<length; i++){
        values[i]=temp[i];
    }
    delete [] temp;
    values[length]=el;
    length++;
}

void TVect::removeElement(int index){
    // Удаление элемента из вектора
    if (index >= zero && index < length){
        Mytype * temp = new Mytype[length];
        for (int i=zero; i<length; i++){
            temp[i]=values[i];
        }
        delete [] values;
        values=new Mytype[length-one];
        for (int i=zero; i<length-one; i++){
            if (i>=index){values[i]=temp[i+one];}
            else {values[i]=temp[i];}
        }
        delete [] temp;
        length--;
    }
}

TVect &TVect::operator += (TVect &q){
    // Перегрузка оператора суммирования
    if (q.length>length){
        Mytype * temp=new Mytype[length];
        for (int i=zero; i<length; i++){temp[i]=values[i];}
        delete [] values;
        values=new Mytype[q.length];
        for (int i=zero; i<length; i++){
            values[i]=temp[i]+q.values[i];
        }
        for (int i=length; i<q.length; i++){
            values[i]=q.values[i];
        }
        length=q.length;
    } else {
        for (int i=zero; i<q.length; i++){
            values[i]+=q.values[i];
        }
    }
    return * this;
}

TVect & TVect::operator -= (TVect & q){
    // Перегрузка оператора вычитания
    if (q.length>length){
        Mytype * temp=new Mytype[length];
        for (int i=zero; i<length; i++){temp[i]=values[i];}
        delete [] values;
        values=new Mytype[q.length];
        for (int i=zero; i<length; i++){
            values[i]=temp[i]-q.values[i];
        }
        for (int i=length; i<q.length; i++){
            values[i]=-q.values[i];
        }
        length=q.length;
    } else {
        for (int i=zero; i<q.length; i++){
            values[i]-=q.values[i];
        }
    }
    return * this;
}

TVect TVect::operator +(TVect & q){
    // Перегрузка сложения двух векторов
    TVect temp(*this);
    temp+=q;
    return temp;
}

TVect TVect::operator -(TVect & q){
    // Перегрузка вычитания двух векторов
    TVect temp(*this);
    temp-=q;
    return temp;
}

TVect & TVect::operator *= (TVect & q){
    // Перегрузка присваивающего умножения
    if (q.length>length){
        Mytype * temp=new Mytype[length];
        for (int i=zero; i<length; i++){temp[i]=values[i];}
        delete [] values;
        values=new Mytype[q.length];
        for (int i=zero; i<length; i++){
            values[i]=temp[i]*q.values[i];
        }
        for (int i=length; i<q.length; i++){
            values[i]=zero;
        }
        length=q.length;
    } else {
        for (int i=zero; i<q.length; i++){
            values[i]*=q.values[i];
        }
        for (int i=q.length; i<length; i++){
            values[i]=zero;
        }
    }
    return * this;
}

TVect & TVect::operator *= (qreal q){
    // Перегрузка присваивающего умножения
    for (int i=zero; i<length; i++){
        values[i]*=q;
    }
    return * this;
}

TVect & TVect::operator = (TVect & q){
    // Перегрузка оператора =
    length=q.length;
    delete [] values;
    values = new Mytype[length];
    for (int i=zero; i<length; i++){
        values[i]=q.values[i];
    }
    return * this;
}

Mytype &TVect::operator [](int index){
    // Перегрузка индекса
    if (index >= zero && index<length){
        return values[index];
    }
    exit (one);
}

TVect TVect::operator *(qreal q){
    // Перегрузка умножения на число
    TVect temp(*this);
    temp*=q;
    return temp;
}

qreal TVect::module(){
    // Вычисление модуля вектора
    qreal temp=zero;
    for (int i=zero; i<length; i++){
        temp+=values[i]*values[i];
    }
    return sqrt(temp);
}

int TVect::getLength(){
    // Возвращает длину
    return length;
}

void TVect::setLength(int newLength){
    // Устанавливает новое значение
    Mytype * temp = new Mytype[length];
    for (int i=zero; i<length; i++){
        temp[i]=values[i];
    }
    delete [] values;
    values=new Mytype[newLength];
    for (int i=zero; i<newLength; i++){
        if (i<length) {
            values[i]=temp[i];
        } else {
            values[i]=zero;
        }
    }
    delete [] temp;
    length=newLength;
}

bool TVect::getElement(int index, Mytype & q){
    if (index >=zero && index<length){
        q=values[index];
        return true;
    } else return false;
}

bool TVect::setElement(int index, Mytype q){
    if (index >=zero && index<length){
        values[index]=q;
        return true;
    } else return false;
}

void setRandom(TVect & q, qreal a, qreal b){
    for(int i=zero; i<q.length; i++){
        q.values[i]=(rand()*(b-a))/RAND_MAX+a;
    }
}

int kkk(){return 3;}
