#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cerrno>
#include <cstdlib>
#include <iomanip>
#include <cctype>

class ScalarConverter
{
    public:

        static void convert(const std::string& literal);

    private:
        
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);
};

bool isSingleChar(const std::string& str);
bool isValidNumber(const std::string& str, double& value);

void convertToChar(double value);
void convertToInt(double value);
void convertToFloat(double value);
void convertToDouble(double value);

#endif /* SCALARCONVERTER_HPP */