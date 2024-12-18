#include <iostream>
#include "Zombie.h"

int main()
{
    unsigned int size;
    while (1)
    {
        std::cout << "Enter number of zombies: ";
        std::cin >> size;
        if (std::cin.eof())
        {
            std::cin.clear();
            return 0;
        }
        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid number of zombies." << std::endl;
        }
        else
            break;
    }
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    Zombie *horde = zombieHorde(size, "Buckethead");
    delete[] horde;
    return 0;
}