#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &)
{
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &)
{
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

bool ScalarConverter::IsChar(std::string const &str)
{
    return (str.size() == 1 && isprint(str[0]) && !isdigit(str[0]));
}

bool ScalarConverter::IsInt(std::string const &str) 
{
    if (str.empty())
        return false;
    size_t i = 0;
    if (str[0] == '+' || str[0] == '-')
        i = 1;
    for (; i < str.size(); ++i) 
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::IsFloat(std::string const &str)
{
    if (str.empty())
        return false;

    size_t i = 0;
    bool Dot_count = false;
    if (str[0] == '+' || str[0] == '-')
        i = 1;
    for (; i < str.size(); ++i)
    {
        if (str[i] == '.') 
        {
            if (Dot_count)
                return false;
            Dot_count = true;
        } 
        else if (str[i] == 'f')
            return i == str.size() - 1 && Dot_count;
        else if (!std::isdigit(str[i]))
            return false;
    }
    return false;
}

bool ScalarConverter::IsDouble(std::string const &str)
{
    if (str.empty())
        return false;
    size_t i = 0;
    bool Dot_count = false;
    if (str[0] == '+' || str[0] == '-')
        i = 1;
    for (; i < str.size(); ++i) 
    {
        if (str[i] == '.') 
        {
            if (Dot_count)
                return false;
            Dot_count = true;
        } 
        else if (!std::isdigit(str[i]))
            return false;
    }
    return Dot_count;
}
bool ScalarConverter::IsSpecial(std::string const &str)
{
    return (str == "-inf" || str == "+inf" || str == "nan" || 
            str == "-inff" || str == "+inff" || str == "nanf");
}
void ScalarConverter::Convert(std::string const &str)
{
    if (IsSpecial(str)) 
    {
        if (str == "nan" || str == "nanf") 
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        } 
        else 
        {
            bool isFloat = (str[str.size() - 1] == 'f');
            if (isFloat)
            {
                float f = std::strtof(str.c_str(), NULL);
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << f << "f" << std::endl;
                std::cout << "double: " << static_cast<double>(f) << std::endl;
            }
            else
            {
                double d = std::strtod(str.c_str(), NULL);
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
                std::cout << "double: " << d << std::endl;
            }
        }
        return;
    }
    if (IsChar(str))
    {
        char c = str[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
    }
    else if (IsInt(str))
    {
        try
        {
            double i = std::atol(str.c_str());
            if (i < 32 || i > 126)
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: " << "'" << static_cast<char>(i) << "'" << std::endl;
            if (i > 2147483647 || i < -2147483648)
                std::cout << "int: impossible" << std::endl;
            else
                std::cout << "int: " << static_cast<int>(i) << std::endl;
            std::cout << std::fixed << "float: " << static_cast<float>(i) << "f" << std::endl;
            std::cout << "double: " << i << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Conversion failed" << std::endl;
        }
    }
    else if (IsFloat(str))
    {
        try
        {
            float f = std::strtof(str.c_str(), NULL);
            if (static_cast<int>(f) < 32 || static_cast<int>(f) > 126)
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: " << "'" << static_cast<char>(f) << "'" << std::endl;
            if (static_cast<double>(f) > 2147483647 || static_cast<double>(f) < -2147483648)
                std::cout << "int: impossible" << std::endl;
            else
                std::cout << "int: " << static_cast<int>(f) << std::endl;
            std::cout << std::fixed << "float: " << f << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(f) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Conversion failed" << std::endl;
        }
    }
    else if (IsDouble(str))
    {
        try
        {
            double d = std::atof(str.c_str());
            if (static_cast<int>(d) < 32 || static_cast<int>(d) > 126)
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: " << "'" << static_cast<char>(d) << "'" << std::endl;
            if (static_cast<double>(d) > 2147483647 || static_cast<double>(d) < -2147483648)
                std::cout << "int: impossible" << std::endl;
            else
                std::cout << "int: " << static_cast<int>(d) << std::endl;
            std::cout << std::fixed << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Conversion failed" << std::endl;
        }
    }
    else
    {
        std::cerr << "Conversion failed" << std::endl;
    }
}
