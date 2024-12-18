#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
        RobotomyRequestForm(void);
    public:
        RobotomyRequestForm(std::string const target);
        RobotomyRequestForm(RobotomyRequestForm const &other);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &form);

#endif