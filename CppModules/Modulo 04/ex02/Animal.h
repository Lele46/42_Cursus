#ifndef A_ANIMAL_H
#define A_ANIMAL_H

#include <iostream>
#include <string>

class A_Animal 
{
    protected:
        std::string _type;
    public:
        virtual void makeSound() const = 0;
        std::string get_type() const;
        
        virtual ~A_Animal();
};

#endif