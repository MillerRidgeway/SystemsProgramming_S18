#include <iostream>
#include <inttypes.h>
#include "VoxelShape.h"
#include "MyArray.h"

int main(){
    //Testing

    //Get & Set
    MyArray<int> m(10);
    for(int i = 0; i < m.getSize(); i++){
        m.set(i,i);
        std::cout << m.get(i) << " ";
    }
    std::cout << std::endl;

    //Resize
    m.resize(30);
    for(int i = 0; i < m.getSize(); i++){
        m.set(i,i);
        std::cout << m.get(i) << " ";
    }
    std::cout << std::endl;

    //PushBack
    m.PushBack(30);
    for(int i = 0; i < m.getSize(); i++){
        std::cout << m.get(i) << " ";
    }
    std::cout << std::endl;

    //Back
    std::cout << m.back() << std::endl;

    //PopBack
    int b = m.PopBack();
    std::cout << b << std::endl;
    for(int i = 0; i < m.getSize(); i++){
        std::cout << m.get(i) << " ";
    }
    std::cout << std::endl;

    int size = 500;
    VoxelShape model(size,size,size);

    model.clearModel();
    model.addSphere(size/2,size/2,size/2,10);

    writeSTL(model,"Tester.stl");

    return 0;
}