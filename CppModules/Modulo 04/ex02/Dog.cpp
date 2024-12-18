#include "Dog.h"

Dog::Dog() : brain(new Brain())
{
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog const &src) : brain(new Brain(*src.get_Brain()))
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &src)
{
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &src)
    {
        _type = src.get_type();
        delete this->brain;
        this->brain = new Brain(*src.get_Brain());
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}

Brain *Dog::get_Brain() const
{
    return this->brain;
}