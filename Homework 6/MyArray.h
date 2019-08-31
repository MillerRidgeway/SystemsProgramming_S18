//
// Created by Miller Ridgeway on 3/1/2018.
//

#ifndef HOMEWORK3_GENARRAY_H
#define HOMEWORK3_GENARRAY_H

#include <clocale>

template <class T>
class MyArray{
public:
    MyArray(int);
    MyArray(const MyArray &);
    ~MyArray();
    MyArray &operator=(const MyArray &);

    T get(int);
    void set(T, int);
    void resize(int);
    const int getSize();
    void PushBack(T item);
    T back();
    T PopBack();

private:
    int size;
    int iCount;
    T *items;
};

template <typename T>
MyArray<T>::MyArray(int s) {
    size = s;
    iCount = s;
    items = new T[s];
}

template <typename T>
MyArray<T>::~MyArray() {
    delete [] items;
}

template <typename T>
MyArray<T>::MyArray(const MyArray &a) {
    items = new T[a.size];
    for(int i = 0; i < a.size; i ++){
        items[i] = a.items[i];
    }
}

template <typename T>
MyArray<T> &MyArray<T>::operator=(const MyArray &a) {
    if(this == &a)
        return *this;
    items = new T[a.size];
    for(int i = 0; i < a.size; i++)
    {
        items[i] = a.items[i];
    }
    return *this;
}

template <typename T>
T MyArray<T>::get(int i) {
    return items[i];
}

template <typename T>
void MyArray<T>::set(T temp, int i) {
    items[i] = temp;
}

template <typename T>
void MyArray<T>::resize(int s) {
    int iter;
    if(s > size)
    {
        iter = s;
        size = s;
        iCount = s;
    }
    else {
        iter = s;
        iCount = s;
    }

    T *temp =  new T[s];
    for(int i = 0; i < iter; i++){
        temp[i] = items[i];
    }
    delete [] items;
    items = temp;

}

template <typename T>
void MyArray<T>::PushBack(T item) {
    iCount += 1;
    if(iCount >= size){
        this->resize(size + 1);
    }

    items[iCount - 1] = item;
}

template <typename T>
T MyArray<T>::PopBack() {
    T temp = items[iCount - 1];
    iCount -= 1 ;
    return temp;
}

template <typename T>
T MyArray<T>::back() {
    return items[iCount - 1];
}

template <typename T>
const int MyArray<T>::getSize() {
    return iCount;
}
#endif //HOMEWORK3_GENARRAY_H
