#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

bool ScalarConverter::isSingleChar(const std::string& str)
{
    return str.length() == 1 && !std::isdigit(str[0]);
}

bool ScalarConverter::isValidNumber(const std::string& str, double& value)
{
    if (str == "nan" || str == "nanf")
    {
        value = std::numeric_limits<double>::quiet_NaN();
        return true;
    }
    else if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
    {
        value = std::numeric_limits<double>::infinity();
        return true;
    }
    else if (str == "-inf" || str == "-inff")
    {
        value = -std::numeric_limits<double>::infinity();
        return true;
    }

    char* endptr;
    errno = 0;
    value = std::strtod(str.c_str(), &endptr);

    if (endptr == str.c_str())
        return false;

    if (!(*endptr == '\0' || (*endptr == 'f' && endptr[1] == '\0')))
        return false;

    return true;
}

void ScalarConverter::convertToChar(double value)
{
    std::cout << "char: ";
    if (value < 0 || value > 127)
        std::cout << "impossible\n";
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(value) << "'\n";
}

void ScalarConverter::convertToInt(double value)
{
    std::cout << "int: ";
    if (value > INT_MAX || value < INT_MIN || errno == ERANGE)
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(value) << "\n";
}

void ScalarConverter::convertToFloat(double value)
{
    std::cout << "float: ";
    if (errno == ERANGE)
        std::cout << "impossible\n";
    else
        std::cout << static_cast<float>(value) << "f\n";
}

void ScalarConverter::convertToDouble(double value)
{
    std::cout << "double: ";
    if (errno == ERANGE)
        std::cout << "impossible\n";
    else
        std::cout << value << "\n";
}

void ScalarConverter::convert(const std::string& literal)
{
    double value;

    if (isSingleChar(literal))
        value = static_cast<double>(literal[0]);
    else if (!isValidNumber(literal, value))
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return ;
    }

    std::cout << std::fixed << std::setprecision(1);
    convertToChar(value);
    convertToInt(value);
    convertToFloat(value);
    convertToDouble(value);
}