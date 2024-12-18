#ifndef CAT_H
#define CAT_H
#include <iostream>
#include <string>
#include "Animal.h"
#include "Brain.h"

class Cat : public Animal
{
    private:
        Brain *brain;

    public:
        void makeSound() const;
        Brain *get_Brain() const;

        Cat();
        Cat(Cat const &src);
        Cat &operator=(Cat const &src);
        ~Cat();
};

#endif