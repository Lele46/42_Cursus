#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("Pippo", 150);
        std::cout << b.getName() << std::endl;
        std::cout << b.getGrade() << std::endl;
        b.incrementGrade();
        std::cout << b.getName() << std::endl;
        std::cout << b.getGrade() << std::endl;
        b.decrementGrade();
        std::cout << b.getName() << std::endl; 
        std::cout << b.getGrade() << std::endl;
        b.decrementGrade();
        std::cout << b.getName() << std::endl;
        std::cout << b.getGrade() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << std::endl;
    try
    {
        Bureaucrat b("Pippo", 1);
        std::cout << b.getName() << std::endl;
        std::cout << b.getGrade() << std::endl;
        b.incrementGrade();
        std::cout << b.getName() << std::endl;
        std::cout << b.getGrade() << std::endl;
        b.incrementGrade();
        std::cout << b.getName() << std::endl;
        std::cout << b.getGrade() << std::endl;
        b.incrementGrade();
        std::cout << b.getName() << std::endl;
        std::cout << b.getGrade() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}