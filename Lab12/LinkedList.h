//
// Created by Miller Ridgeway on 2/12/2018.
//

#ifndef LAB10_LINKEDLIST_H
#define LAB10_LINKEDLIST_H


#include <clocale>
#include <iostream>

template <typename T>
class LinkedList{
    public:
        LinkedList();
        ~LinkedList();
        bool isEmpty();
        void insertAtHead(T v);
        T PeekHead();
        T RemoveHead();
        void printList();

    private:
        struct Node { T item; Node* next; };
        Node* head;
};

template <typename T>
LinkedList<T>::LinkedList() {
    head = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList(){
    delete head;
}

template <typename T>
bool LinkedList<T>::isEmpty() {
    return head == NULL;
}

template <typename T>
void LinkedList<T>::insertAtHead(T v) {
    Node* temp = new Node;

    temp->item = v;
    temp->next = head;

    head = temp;
}

template <typename T>
T LinkedList<T>::PeekHead() {
    return head->item;
}

template <typename T>
T LinkedList<T>::RemoveHead(){
    Node* temp = new Node;
    T val;

    val = head->item;
    temp = head->next;

    delete head;
    head = temp;

    return val;
}

template <typename T>
void LinkedList<T>::printList(){
    Node* curr;
    curr = head;

    while(curr != nullptr){
        std::cout << curr->item;
        curr = curr->next;
    }
    std::cout << std::endl;
}

#endif //LAB10_LINKEDLIST_H
