#include "Cat.h"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat const &src) : Animal(src.get_type())
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}


