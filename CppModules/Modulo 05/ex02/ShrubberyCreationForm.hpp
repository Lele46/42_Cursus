#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
        ShrubberyCreationForm(void);
    public:
        ShrubberyCreationForm(std::string const target);
        ShrubberyCreationForm(ShrubberyCreationForm const &other);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &form);

#endif