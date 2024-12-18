#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        // Creazione di un modulo con grado minimo per firma 50 e per esecuzione 25
        Form formA("FormA", 50, 25);
        Bureaucrat bob("Bob", 45); // Bureaucrat con grado 45
        Bureaucrat alice("Alice", 55); // Bureaucrat con grado 55

        std::cout << formA << std::endl;

        // Tentativo di firma da parte di Bob (con grado sufficiente)
        bob.signForm(formA);
        std::cout << formA << std::endl;

        // Tentativo di firma da parte di Alice (con grado insufficiente)
        alice.signForm(formA);
    }
    catch (const std::exception &e) {
        std::cerr << "Eccezione: " << e.what() << std::endl;
    }

    std::cout << "------------------------------------" << std::endl;

    try {
        Form invalidForm("InvalidForm", 0, 150);
    }
    catch (const std::exception &e) {
        std::cerr << "Eccezione: " << e.what() << std::endl;
    }

    std::cout << "------------------------------------" << std::endl;

    try {
        Form invalidForm("InvalidForm", 200, 25);
    }
    catch (const std::exception &e) {
        std::cerr << "Eccezione: " << e.what() << std::endl;
    }

    return 0;
}