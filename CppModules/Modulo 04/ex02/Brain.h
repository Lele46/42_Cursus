#ifndef BRAIN_H
#define BRAIN_H
#include <iostream>
#include <string>
#include "Animal.h"

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(Brain const &src);
        Brain &operator=(Brain const &src);
        virtual ~Brain();

        void set_Idea(int index, std::string idea);
        std::string get_Idea(int index) const;
};

#endif