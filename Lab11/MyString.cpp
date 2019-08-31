//
// Created by Miller Ridgeway on 2/14/2018.
//

#include <cstddef>
#include <cstring>
#include "MyString.h"
#include <cString>
#include <iostream>

MyString::MyString(){
    string = new char[1];
}

MyString::MyString(const MyString &other){
     string = new char[strlen(other.string) + 1];

    for(int i = 0; i<strlen(other.string); i++){
        string[i]  = other.string[i];
    }

    string[strlen(other.string)] = 0;
}

MyString::MyString(const char *assign){
    string = new char[strlen(assign) + 1];

    for(int i = 0; i<strlen(assign); i++){
        string[i]  = assign[i];
    }
}

MyString::~MyString(){
    delete [] string;
}

MyString &MyString::operator=(const MyString &other) {
    if (string != other.string) {
        char *temp = new char[strlen(other.string) + 1];
        string = new char[strlen(other.string) + 1];

        for (int i = 0; i < strlen(other.string); i++) {
            temp[i] = other.string[i];
        }
        temp[strlen(other.string)] = 0;
        string = temp;
        return *this;
    }
    else
    {
        return *this;
    }
}

size_t MyString::length() const {
    return strlen(string);
}

const char* MyString::cString() const{
    return string;
}