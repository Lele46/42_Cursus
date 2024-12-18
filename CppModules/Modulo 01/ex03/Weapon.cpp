#include "Weapon.h"

Weapon::Weapon(std::string type)
{
    this->type = type;
}

const std::string& Weapon::getType() const
{
    return this->type;
}

void Weapon::setType(std::string newtype)
{
    this->type = newtype;
}