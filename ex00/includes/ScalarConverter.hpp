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

        static bool isSingleChar(const std::string& str);
        static bool isValidNumber(const std::string& str, double& value);

        static void convertToChar(double value);
        static void convertToInt(double value);
        static void convertToFloat(double value);
        static void convertToDouble(double value);
};

#endif /* SCALARCONVERTER_HPP */