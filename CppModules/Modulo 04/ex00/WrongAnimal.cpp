#include "WrongAnimal.h"

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "WrongAnimal: " << this->_type << " constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal: " << this->_type << " destructor called" << std::endl;
}

std::string WrongAnimal::get_type() const
{
    return this->_type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sounds" << std::endl;
}