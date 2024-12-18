#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form constructor called" << std::endl;
    _signed = false;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
    _signed = other._signed;
}

Form &Form::operator=(Form const &other)
{
    std::cout << "Form assign operator called" << std::endl;
    _signed = other._signed;
    return (*this);
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

std::string const &Form::getName() const
{
    std::cout << "Form: get Bureaucrat name called" << std::endl;
    return (_name);
}

bool Form::getSigned() const
{
    std::cout << "Form: get signed called" << std::endl;
    return (_signed ? "signed" : "not signed");
}

int Form::getGradeToSign() const
{
    std::cout << "Form: getGradeToSign called" << std::endl;
    return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
    std::cout << "Form: getGradeToExecute called" << std::endl;
    return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat const &signer)
{
    if (signer.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    else
    {
        _signed = true;
        std::cout << signer.getName() << " signs " << _name << std::endl;
    }
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << form.getName() << " is " << form.getSigned() << " and requires a grade of " << form.getGradeToSign() << " to sign and " << form.getGradeToExecute() << " to execute.";
    return out;
}
