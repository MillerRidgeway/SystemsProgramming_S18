//
//  main.cpp
//  HelloWorld
//
//  Created by Miller Ridgeway on 1/3/18.
//  Copyright © 2018 Miller Ridgeway. All rights reserved.
// I am changing this file to test SVN Update

#include <iostream>

int main(int argc, const char * argv[]) {
    
    std::string name;
    
    std::cout << "What is your name? ";
    std::cin >> name;
    std::cout << "Greetings, " + name + ", from a C++ program. \n";
    
    return 0;
}
