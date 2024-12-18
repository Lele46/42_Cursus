#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        // Crea dei Bureaucrat con gradi diversi
        Bureaucrat highRank("Alice", 1);  // Grado massimo
        Bureaucrat midRank("Bob", 50);
        Bureaucrat lowRank("Charlie", 100);  // Grado minimo

        std::cout << "\n--- Test: ShrubberyCreationForm ---\n";
        ShrubberyCreationForm shrubbery("Home");
        std::cout << shrubbery << std::endl;

        // Tentativo di esecuzione senza firma
        try {
            lowRank.executeForm(shrubbery);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        // Firma e esecuzione con lowRank
        lowRank.signForm(shrubbery);
        midRank.executeForm(shrubbery);

        std::cout << "\n--- Test: RobotomyRequestForm ---\n";
        RobotomyRequestForm robotomy("Un tizio random");
        std::cout << robotomy << std::endl;

        // Firma e esecuzione con gradi insufficienti
        try {
            lowRank.signForm(robotomy);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        midRank.signForm(robotomy);
        highRank.executeForm(robotomy);  // Esegue con successo

        std::cout << "\n--- Test: PresidentialPardonForm ---\n";
        PresidentialPardonForm pardon("Pino");
        std::cout << pardon << std::endl;

        // Tentativo di firma ed esecuzione con gradi insufficienti
        try {
            midRank.signForm(pardon);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        highRank.signForm(pardon);
        highRank.executeForm(pardon);

    } catch (const std::exception &e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}