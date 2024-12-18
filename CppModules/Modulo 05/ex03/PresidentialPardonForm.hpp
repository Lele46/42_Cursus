#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
        PresidentialPardonForm(void);
    public:
        PresidentialPardonForm(std::string const target);
        PresidentialPardonForm(PresidentialPardonForm const &other);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm const &form);

#endif