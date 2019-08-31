//
// Created by Miller Ridgeway on 2/14/2018.
//

#include <cstddef>
#include <cstring>
#include "MyString.h"
#include <cString>
#include <iostream>

MyString::MyString()
{
    string = new char[1];
    string[0] = '\0';
}

MyString::MyString(const MyString& s)
{
    string = new char[s.length()+1];
    for(int i=0; i < s.length(); i++)
    {
        string[i] = s.string[i];
    }
    string[s.length()] = '\0';

}

MyString::MyString(const char *s)
{
    string = new char[strlen(s)+1];

    for(int i=0; i < strlen(s); i++)
    {
        string[i] = s[i];
    }
    string[strlen(s)] = '\0';

}

MyString::~MyString()
{
    delete[] string;
    string = NULL;
}

MyString& MyString::operator=(const MyString& s)
{
    if(this == &s) return *this;

    string = new char[s.length()+1];
    for(int i=0; i < s.length(); i++)
    {
        string[i] = s.string[i];
    }
    string[s.length()] = '\0';

    return *this;

}

size_t MyString::length() const
{
    return strlen(string);
}

const char* MyString::cString() const
{
    return string;
}


std::ostream& operator<<(std::ostream& os, const MyString& s){
    os << s.cString();
    return os;
}

MyString operator+(const MyString &s1, const MyString &s2){
    MyString temp;

    for(int i = 0; i < s1.length(); i++){
        temp[i] = s1[i];
    }

    int j = 0;
    for(int i = s1.length(); i < s1.length() + s2.length(); i++){
        temp[i] = s2[j];
        j++;
    }

    temp[temp.length()] = '\0';
    return temp;
}
