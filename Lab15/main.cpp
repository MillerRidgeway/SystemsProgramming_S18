#include <iostream>
#include "MyString.h"

int main(int argc, const char * argv[])
{
    MyString *s = new MyString();
    std::cout << "Empty: '" << *s << "'\n";
    *s = "hello";
    std::cout << "After operator=: '" << *s << "'\n";
    {
        MyString *t = new MyString(*s);
        std::cout << "After copy: '" << *t << "'\n";
        *s = *t;
    }

    MyString *m = new MyString("world");
    std::cout << "After constructor: '" << *m << "'\n";
    *m = *s;
    std::cout << "After operator=: '" << *m << "'\n";
    *m = *m;
    std::cout << "After operator=: '" << *m << "'\n";

    *s += ",";
    *s += *m;
    std::cout << "After operator +=: " << *s << "\n";
    *s += ",goodbye";
    std::cout << "After operator +=: " << *s << "\n";

    MyString *abc = new MyString("abc");
    *abc += *abc;
    std::cout << "After operator += to self: " << *abc << "\n";

    MyString *sum = new MyString("2+2=");
    *sum = *sum + "5?";
    std::cout << "After operator +: " << *sum << "\n";

    (*sum)[4] = '4';
    (*sum)[5] = '!';
    std::cout << "After operator []:" << *sum << "\n";

    const MyString *u = new MyString("A const string.");
    std::cout << "Using const []: ";
    for (size_t i = 0; i < u->length(); ++i) {
        std::cout << (*u)[i];
    }

    delete s;
    delete m;
    delete abc;
    delete sum;
    delete u;

    std::cout << "\n";

    return 0;
}