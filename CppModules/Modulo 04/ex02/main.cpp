#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

int main()
{
    A_Animal *a = new Cat();
    A_Animal *b = new Dog();
 
    a->makeSound();
    b->makeSound();

    delete a;
    delete b;
    
    return 0;
}