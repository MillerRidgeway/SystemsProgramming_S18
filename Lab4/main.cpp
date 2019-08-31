#include <iostream>
#include <chrono>
#include <ctime>

//Swap Functions
//Cannot pass by value
void swap_value(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void swap_reference(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void swap_pointer(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Struct Swap
struct pair {
    int a, b;
};

//Cannot pass by value
void swap_value(pair p){
    int temp = p.a;
    p.a = p.b;
    p.b = temp;
}

void swap_reference(pair &p){
    int temp = p.a;
    p.a = p.b;
    p.b = temp;
}

void swap_pointer(pair *p){
    int temp = p -> a;
    p -> a = p -> b;
    p -> b = temp;
}

//Large struct
struct storage {
    int foo[10000];
};

void sumVal(int a[10000]){
    int sum = 0;

    for (int i = 0; i < 10; i++)
    {
        sum += a[i];
    }
    //std::cout << "Sum (val): " << sum << std::endl;
}

void sumRef(int (&a)[10000]){
    int sum = 0;

    for(int i = 0; i < 10; i++){
       sum += a[i];
    }

    //std::cout << "Sum (ref): " << sum << std::endl;
}

int main() {
    //Integer Swapping
    int x = 0;
    int y = 1;

    std::cout << "X: " << x << " Y: " << y << std::endl;
    swap_value(x,y);
    std::cout << "Swap by value" << std::endl;
    std::cout << "X: " << x << " Y: " << y << std::endl;

    std::cout << "\n";
    x = 0;
    y = 1;

    std::cout << "X: " << x << " Y: " << y << std::endl;
    swap_reference(x,y);
    std::cout << "Swap by reference" << std::endl;
    std::cout << "X: " << x << " Y: " << y << std::endl;

    std::cout << "\n";
    x = 0;
    y = 1;

    std::cout << "X: " << x << " Y: " << y << std::endl;
    swap_pointer(&x,&y);
    std::cout << "Swap by pointer" << std::endl;
    std::cout << "X: " << x << " Y: " << y << std::endl;

    std::cout << std::endl;

    //Pair Swapping
    pair p1;
    p1.a = 0;
    p1.b = 1;

    std::cout << "X: " << p1.a << " Y: " << p1.b << std::endl;
    swap_value(p1);
    std::cout << "Swap by value (pair)" << std::endl;
    std::cout << "X: " << p1.a << " Y: " << p1.b << std::endl;

    std::cout << "\n";
    p1.a = 0;
    p1.b = 1;

    std::cout << "X: " << p1.a << " Y: " << p1.b << std::endl;
    swap_reference(p1);
    std::cout << "Swap by reference (pair)" << std::endl;
    std::cout << "X: " << p1.a << " Y: " << p1.b << std::endl;

    std::cout << "\n";
    p1.a = 0;
    p1.b = 1;

    std::cout << "X: " << p1.a << " Y: " << p1.b << std::endl;
    swap_pointer(&p1);
    std::cout << "Swap by pointer (pair)" << std::endl;
    std::cout << "X: " << p1.a << " Y: " << p1.b << std::endl;

    std::cout << "\n";

    //Large struct
    storage s1;

    for(int i = 0; i <= 10000; i++){
        s1.foo[i] = i;
    }

    //Timing
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    int i = 0;
    while(i <= 10000){
        //sumVal(s1.foo);
        sumRef(s1.foo);
        i++;
    }

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";

    return 0;
}