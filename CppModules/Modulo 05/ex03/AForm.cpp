#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form constructor called" << std::endl;
    _signed = false;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
    _signed = other._signed;
}

AForm &AForm::operator=(AForm const &other)
{
    std::cout << "Form assign operator called" << std::endl;
    _signed = other._signed;
    return (*this);
}

AForm::~AForm()
{
    std::cout << "Form destructor called" << std::endl;
}

std::string const &AForm::getName() const
{
    std::cout << "Form: get Bureaucrat name called" << std::endl;
    return (_name);
}

std::string const &AForm::getFormName() const
{
    std::cout << "Form: getFormName called" << std::endl;
    return (_name);
}

bool AForm::getSigned() const
{
    return _signed;
}

int AForm::getGradeToSign() const
{
    std::cout << "Form: getGradeToSign called" << std::endl;
    return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
    std::cout << "Form: getGradeToExecute called" << std::endl;
    return (_gradeToExecute);
}

void AForm::beSigned(Bureaucrat const &signer)
{
    if (signer.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    else
    {
        _signed = true;
        std::cout << signer.getName() << " signs " << _name << std::endl;
    }
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char *AForm::FormnotSignedException::what() const throw()
{
    return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << form.getName() << " is " << form.getSigned() << " and requires a grade of " << form.getGradeToSign() << " to sign and " << form.getGradeToExecute() << " to execute.";
    return out;
}
