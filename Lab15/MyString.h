//
// Created by Miller Ridgeway on 2/14/2018.
//

#ifndef LAB11_MYSTRING_H
#define LAB11_MYSTRING_H

#include <iostream>
#include <string.h>

class MyString {
public:
	MyString();
	MyString(const MyString &);
	MyString(const char *);
	~MyString();

	MyString &operator=(const MyString & s);

    MyString &operator+=(const MyString& s){
        int newLen  = this->length() + s.length();
        MyString temp = MyString(*this);

        this->string = new char[newLen + 1];

        for(int i = 0; i < temp.length(); i++)
            this->string[i] = temp.string[i];

        int j = 0;
        for(int i = temp.length(); i < newLen; i++) {
            this->string[i] = s.string[j];
            j++;
        }

        this->string[newLen] = '\0';
        return *this;
    }

    char operator[](size_t i) const{
        if(i < 0 || i > this->length())
            return 0;
        return this->string[i];
    }

    char &operator[](size_t i){
        if(i < 0 || i > this->length())
            return string[length()];
        return this->string[i];
    }

	size_t length() const;
	const char *cString() const;

private:
	char *string;
};


MyString operator+(const MyString &s1, const MyString &s2);

std::ostream& operator<<(std::ostream& os, const MyString& s);


#endif //LAB11_MYSTRING_H
