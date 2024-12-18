#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal 
{
    protected:
        std::string _type;
    public:
        virtual void makeSound() const;
        std::string get_type() const;
        
        Animal();
        Animal(std::string type);
        virtual ~Animal();
};

#endif