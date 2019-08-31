#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdint>

int main() {
    std::vector<uint64_t> fib;
    std::unordered_map<uint64_t, int> fibMap;

    //Initial Values
    fib.push_back(0);
    fib.push_back(1);
    fib.push_back(1);

    fibMap[1] = 2;

    //Fill in sequence
    for(int i = 3; i < 94; i++){
        uint64_t num = fib[i - 1] + fib[i - 2];
        fib.push_back(num);
        fibMap[num] = i;
    }

    //Printing Vector
    std::cout << "Fibonacci numbers in order:" << std::endl;

    int index = 0;
    for(auto i = fib.begin(); i != fib.end(); i++){
        std::cout << index << " " << *i << std::endl;
        index++;
    }

    //Printing Map
    std::cout << "Fibonacci numbers and indices, unordered:" << std::endl;

    for(auto i = fibMap.begin(); i != fibMap.end(); i++){
        std::cout << i->second << " " << i->first << std::endl;
    }

    //Search and print
    std::cout << "Testing Fibonacci numbers from 1 to 15:" << std::endl;

    for(int i = 1; i < 16; i++){
        auto search = fibMap.find(i);
        if(search != fibMap.end()){
            std::cout << i << " " << search->second << std::endl;
        } else
            std::cout << i << " " << "no" << std::endl;

    }

    return 0;
}