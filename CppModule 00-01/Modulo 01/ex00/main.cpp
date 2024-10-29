#include <iostream>
#include "Zombie.h"

int main()
{
    std::string zombiename;
    std::cout << "Enter a zombie name: ";
    std::getline(std::cin, zombiename);
    if (std::cin.eof())
    {
        std::cin.clear();
        return 0;
    }
    Zombie *heapZombie = newZombie(zombiename);
    heapZombie->announce();
    delete heapZombie;
    std::cout << "Enter a zombie name: ";
    std::getline(std::cin, zombiename);
    if (std::cin.eof())
    {
        std::cin.clear();
        return 0;
    }
    randomChump(zombiename);
    return 0;
}
