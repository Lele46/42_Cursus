#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *ptr = &str;
    std::string &ref = str;
    std::cout << "Memory address String: " << &str << std::endl;
    std::cout << "Memory address Pointer: " << ptr << std::endl;
    std::cout << "Memory address Reference: " << &ref << std::endl;
    std::cout << "String Values: " << str << std::endl;
    std::cout << "Pointer Values: " << *ptr << std::endl;
    std::cout << "Reference Values: " << ref << std::endl;
    return 0;
}