#pragma once
#include <string>
#include <iostream>

class Weapon
{
    private:
        std::string type;
    public:
        void setType(std::string type);
        const std::string& getType() const;
        Weapon(std::string type);
        Weapon();
};