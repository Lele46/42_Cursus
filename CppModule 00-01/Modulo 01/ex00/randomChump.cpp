#include "Zombie.h"

void randomChump(std::string name)
{
    Zombie stackzombie(name);
    stackzombie.announce();
}