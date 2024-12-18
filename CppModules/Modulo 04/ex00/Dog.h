#ifndef DOG_H
#define DOG_H
#include <iostream>
#include <string>
#include "Animal.h"

class Dog : public Animal
{
    public:
        void makeSound() const;
        
        Dog();
        Dog(Dog const &src);
        virtual ~Dog();
};

#endif