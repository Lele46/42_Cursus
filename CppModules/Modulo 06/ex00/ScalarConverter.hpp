#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cmath>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &);
        ScalarConverter &operator=(ScalarConverter const &);
        ~ScalarConverter();

        static bool IsChar(std::string const &str);
        static bool IsInt(std::string const &str);
        static bool IsFloat(std::string const &str);
        static bool IsDouble(std::string const &str);
        static bool IsSpecial(std::string const &str);

    public:
        static void Convert(std::string const &str);
};

#endif
