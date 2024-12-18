#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>
#include <string>

class WrongAnimal 
{
    protected:
        std::string _type;
    public:
        void makeSound() const;
        std::string get_type() const;
        
        WrongAnimal(std::string type);
        virtual ~WrongAnimal();
};

#endif