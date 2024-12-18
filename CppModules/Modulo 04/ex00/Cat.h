#ifndef CAT_H
#define CAT_H
#include <iostream>
#include <string>
#include "Animal.h"

class Cat : public Animal
{
    public:
        void makeSound() const;

        Cat();
        Cat(Cat const &src);
        virtual ~Cat();
};

#endif