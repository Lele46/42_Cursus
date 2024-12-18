#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(Intern const &target);
        Intern &operator=(Intern const &target);
        virtual ~Intern();

        AForm *makeForm(std::string const &formName, std::string const &target);

    class UnknownForm : public std::exception
    {
        public:
            const char *what() const throw();
    };
};

#endif