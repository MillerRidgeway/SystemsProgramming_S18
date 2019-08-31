#include <iostream>
#include <string>

template <class T> void readAndPrint(std::string s){
    T var;

    std::cout << "Please input a(n) " << s << ": ";
    std::cin >> var;

    std::cout << "Decimal: " << var << std::endl;
    std::cout << "Hex: " << std::hex << var << std::endl;
}

int main() {
    readAndPrint<uint16_t>("uint16_t");
}