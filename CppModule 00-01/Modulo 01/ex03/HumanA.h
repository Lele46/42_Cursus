#pragma once
#include <string>
#include <iostream>
#include "Weapon.h"

class HumanA
{
    private:
        std::string name;
        Weapon &weapon;
    public:
        HumanA(std::string name, Weapon &weapon);
        void attack() const;
};