//
//  main.cpp
//  Lab9
//
//  Created by Computer Science on 2/1/16.
//  Copyright (c) 2016 Computer Science. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

int main(int argc, const char *argv[]) {
    LinkedList<uint64_t> list;
    LinkedList<std::string> strList;

    //Inserting
    for (int i = 0; i < 10; i++) {
        list.insertAtHead(i);
    }

    for(int i = 0; i < 10; i++){
        strList.insertAtHead("No." + std::to_string(i));
    }

    //Peeking
    std::cout << "Head: " << list.PeekHead() << std::endl;
    list.printList();

    std::cout << "Head: " << strList.PeekHead() << std::endl;
    strList.printList();

    //Removal
    std::cout << "Removed: " << list.RemoveHead() << std::endl;
    list.printList();

    std::cout << "Removed: " << strList.RemoveHead() << std::endl;
    strList.printList();

    for(int i = 0; i < 9; i++){
        strList.RemoveHead();
    }

    for(int i = 0; i < 9; i++){
        list.RemoveHead();
    }

    //Is Empty
    std::cout << std::boolalpha << "Empty List: " << strList.isEmpty() << std::endl;
    std::cout << "Empty List: " << list.isEmpty() << std::endl;
    return 0;
}
