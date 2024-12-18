#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal 
{
    public:
        void makeSound() const;
        
        WrongCat();
        virtual ~WrongCat();
};

#endif