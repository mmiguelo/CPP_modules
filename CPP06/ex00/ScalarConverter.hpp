#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <climits>
# include <cfloat>
# include <cctype>
# include <cstdlib>

# define R		"\033[0;31m" //RED
# define G		"\033[0;32m" //GREEN
# define Y		"\033[0;33m" //YELLOW
# define B		"\033[0;34m" //BLUE
# define RST		"\033[0m"   //RESET

enum Type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    FLOAT_PSEUDO,
    DOUBLE_PSEUDO,
    INVALID
};

class ScalarConverter 
{
    private:
        ScalarConverter();                 // Default constructor
    	ScalarConverter(const ScalarConverter &other); // Copy constructor
        ~ScalarConverter();                // Destructor
        ScalarConverter &operator=(const ScalarConverter &other); // Copy assignment
    public:
        static void convert(const std::string &literal);
};

#endif
