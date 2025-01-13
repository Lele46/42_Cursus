#include "Base.hpp"

int main()
{
    Base* instance = generate();
    std::cout << "Using pointer: ";
    identify(instance);
    std::cout << "Using reference: ";
    identify(*instance);
    delete instance;
    identify(NULL);
    return 0;
}