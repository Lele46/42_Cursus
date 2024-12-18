#include "Cat.h"

Cat::Cat() : brain(new Brain())
{
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat const &src) : brain(new Brain(*src.get_Brain()))
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &src)
{
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &src)
    {
        _type = src.get_type();
        delete this->brain;
        this->brain = new Brain(*src.get_Brain());
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}

Brain *Cat::get_Brain() const
{
    return this->brain;
}
