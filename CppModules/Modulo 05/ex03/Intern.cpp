#include "Intern.hpp"

const char *Intern::UnknownForm::what() const throw()
{
    return ("Error 404: Form not found");
}

Intern::Intern()
{
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(Intern const &target)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = target;
}

Intern &Intern::operator=(Intern const &target)
{
    std::cout << "Intern assign operator called" << std::endl;
    if (this == &target)
    {
        *this = target;
    }
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

static AForm *makePresident(const std::string target)
{
    return (new PresidentialPardonForm(target));
}

static AForm *makeRobot(const std::string target)
{
    return (new RobotomyRequestForm(target));
}

static AForm *makeShrubbery(const std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
   AForm *(*AllForms[3])(std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
    std::string forms[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    for (int i = 0; i < 3; i++)
    {
        if (formName == forms[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return AllForms[i](target);
        }
    }
    throw UnknownForm();
    return (NULL);
}
