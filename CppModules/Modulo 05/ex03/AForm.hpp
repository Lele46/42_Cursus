#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
    private:
        std::string const _name;
        bool _signed;
        int const _gradeToSign;
        int const _gradeToExecute;
    public:
        AForm(std::string const name, int gradeToSign, int gradeToExecute);
        AForm(AForm const &other);
        AForm &operator=(AForm const &other);
        virtual ~AForm();

        std::string const &getName() const;
        std::string const &getFormName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat const &bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;

        class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
        class FormnotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};
std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif