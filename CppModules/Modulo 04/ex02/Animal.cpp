#include "Animal.h"

A_Animal::~A_Animal()
{
    std::cout << "Animal: " << this->_type << " destructor called" << std::endl;
}

std::string A_Animal::get_type() const
{
    return this->_type;
}

void A_Animal::makeSound() const
{
    if (this->_type == "Dog" && this->_type == "Cat")
        std::cout << this->_type << " sounds" << std::endl;
    else
        std::cout << "Shhhh" << std::endl;
}