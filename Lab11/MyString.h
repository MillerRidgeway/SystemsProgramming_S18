//
// Created by Miller Ridgeway on 2/14/2018.
//

#ifndef LAB11_MYSTRING_H
#define LAB11_MYSTRING_H

class MyString {
public:
	MyString();
	MyString(const MyString &);
	MyString(const char *);
	~MyString();
	MyString &operator=(const MyString &);
	size_t length() const;
	const char *cString() const;
private:
	char *string;
};

#endif //LAB11_MYSTRING_H
