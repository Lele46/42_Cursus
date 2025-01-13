#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Invalid number of argument\n";
        return 1;
    }
    ScalarConverter::Convert(argv[1]);
    return 0;
}