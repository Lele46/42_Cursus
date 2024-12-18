#ifndef DOG_H
#define DOG_H
#include <iostream>
#include <string>
#include "Animal.h"
#include "Brain.h"

class Dog : public A_Animal
{
    private:
        Brain *brain;

    public:
        void makeSound() const;
        Brain *get_Brain() const;
        
        Dog();
        Dog(Dog const &src);
        Dog &operator=(Dog const &src);
        ~Dog();
};

#endif