#include "Animal.h"

Animal::Animal() : _type("Animal")
{
    std::cout << "Animal: " << this->_type << " constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal: " << this->_type << " constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal: " << this->_type << " destructor called" << std::endl;
}

std::string Animal::get_type() const
{
    return this->_type;
}

void Animal::makeSound() const
{
    if (this->_type == "Dog" && this->_type == "Cat")
        std::cout << this->_type << " sounds" << std::endl;
    else
        std::cout << "Shhhh" << std::endl;
}