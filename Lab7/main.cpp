#include <iostream>
#include <cstring>


void stackOverflow(){
  stackOverflow();
}

char* reverseString(const char *input_string)
{
    //Empty case
    if(input_string == ""){
        std::cout << "WARNING: Empty input" << std::endl;
        return "";
    }
    //Null case
    else if(input_string == NULL){
        std::cout << "WARNING: Null input" << std::endl;
        return "";
    }
    //Reverse string
    int len = strlen(input_string);
    char* newString = new char[len + 1];

    for(int i = 0; i < len; i++) {
        newString[i] = input_string[(len - 1) - i];
    }
    newString[len] = '\0';

    return newString;
}

int main() {
    //Overflow
    //stackOverflow();

    //Reverse string
    std::cout << "Original string: Hello World" << std::endl;
    char * c = "Hello World";
    std::cout << "Reversed String: " << reverseString(c) << std::endl;
    delete [] c;
}