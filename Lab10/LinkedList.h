//
// Created by Miller Ridgeway on 2/12/2018.
//

#ifndef LAB10_LINKEDLIST_H
#define LAB10_LINKEDLIST_H

#include "Node.h"

class LinkedList{
    public:
        LinkedList();
        void insertAtHead(int v);
        void printList();
        void freeList();

    private:
        Node* head;
};

#endif //LAB10_LINKEDLIST_H
