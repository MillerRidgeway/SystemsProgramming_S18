//
// Created by Miller Ridgeway on 2/12/2018.
//

#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
    head = NULL;
}

void LinkedList::insertAtHead(int v) {
    Node* temp = new Node;

    temp->SetValue(v);
    temp->SetNext(head);

    head = temp;
}

void LinkedList::printList() {
    Node* curr;
    curr = head;

    while(curr != nullptr){
        curr->PrintNode();
        curr = curr->GetNext();
    }

    std::cout << "List Printed" << std::endl;
}

void LinkedList::freeList() {
    while(head != nullptr){
        Node* temp = head;
        head = head->GetNext();
        delete temp;
    }
}
