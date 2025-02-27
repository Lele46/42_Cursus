#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    std::cout << "pushed 5 values: 1-2-3-4-5" << std::endl;
    try
    {
        easyfind(v, 3);
        std::cout << "Searching value '3'" << std::endl;
        std::cout << "Existent value" << std::endl;
    }
    catch (const ValueNotFound &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "Searching value '6'" << std::endl;
        easyfind(v, 6);
        std::cout << "Existent value" << std::endl;
    }
    catch (const ValueNotFound &e)
    {
        std::cout << e.what() << std::endl;
    }
    
}