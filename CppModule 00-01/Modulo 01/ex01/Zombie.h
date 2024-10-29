#pragma once
#include <string>
#include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        void announce();
        void setname(std::string name);
        Zombie(std::string name);
        Zombie();
        ~Zombie();
};
Zombie *zombieHorde(int N, std::string name);