#include "Dog.h"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src.get_type())
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}