#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << "-------Invalid Form-------" << std::endl;
    std::cout << std::endl;
    try
    {
        Intern intern;
        AForm *form;
        form = intern.makeForm("ERR", "Missingno");
        delete form;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "-------Valid Forms-------" << std::endl;
    std::cout << std::endl;

    Intern intern;
    Bureaucrat bureaucrat("Gino", 1);
    AForm *form;
    AForm *form2;
    AForm *form3;

    form = intern.makeForm("PresidentialPardonForm", "Pino");
    delete form;

    form2 = intern.makeForm("RobotomyRequestForm", "Lino");
    bureaucrat.signForm(*form2);
    bureaucrat.executeForm(*form2);
    delete form2;

    form3 = intern.makeForm("ShrubberyCreationForm", "Nino");
    delete form3;

    return (0);
}
