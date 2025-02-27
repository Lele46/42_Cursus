#include "Iter.hpp"

static void ToUpper(char &c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
}

static void ToLower(char &c)
{
    if (c >= 'A' && c <= 'Z')
        c += 32;
}

int main()
{
    char tab[] = {'c', 'i', 'a', 'o'};
    size_t size = sizeof(tab) / sizeof(char);

    std::cout << "\n---- Array originale ----\n" << std::endl;
    for (size_t i = 0; i < 5; ++i)
        std::cout << tab[i] << std::endl;
    std::cout << "\n---- Iter ToUpper ----\n" << std::endl;
    iter(tab, size, ToUpper);
    for (size_t i = 0; i < 5; ++i)
        std::cout << tab[i] << std::endl;
    std::cout << "\n---- Iter ToLower ----\n" << std::endl;
    iter(tab, size, ToLower);
    for (size_t i = 0; i < 5; ++i)
        std::cout << tab[i] << std::endl;
}