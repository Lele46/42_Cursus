#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    std::cout << "Bureaucrat " << _name << " constructor called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name)
{
    std::cout << "Bureaucrat " << _name << " copy constructor called" << std::endl;
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    std::cout << "Bureaucrat " << _name << " assignation operator called" << std::endl;
    _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << _name << " destructor called" << std::endl;
}

std::string const &Bureaucrat::getName() const
{
    std::cout << "Bureaucrat " << _name << " getName called" << std::endl;
    return _name;
}

int Bureaucrat::getGrade() const
{
    std::cout << "Bureaucrat " << _name << " getGrade called" << std::endl;
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    std::cout << "Bureaucrat " << _name << " incrementGrade called" << std::endl;
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    std::cout << "Bureaucrat " << _name << " decrementGrade called" << std::endl;
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm &form)
{
    std::cout << "Bureaucrat " << _name << " signForm called" << std::endl;
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signs " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    std::cout << "Bureaucrat " << _name << " attempts to execute form " << form.getName() << std::endl;
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << _name << " could not execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    out << "Bureaucrat " << bureaucrat.getName() << " has grade " << bureaucrat.getGrade() << std::endl;
    return out;
}