#include "Zombie.h"

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *horde = new Zombie[N];
    if (N <= 0)
    {
        std::cout << "Invalid number of zombies." << std::endl;
        return NULL;
    }
    for (int i = 0; i < N; i++)
    {
        horde[i].setname(name);
        horde[i].announce();
    }
    return horde;
}