#include "../ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << G << "ScalarConverter: defualt constructor called" << RST << std::endl;
}  // Default constructor

ScalarConverter::~ScalarConverter()
{
	std::cout << R << "ScalarConverter: destructor called" << RST << std::endl;
} // Destructor

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
    std::cout << G << "ScalarConverter: Copy constructor called." << RST << std::endl;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &other) {
    if (this != &other)
        *this = other;
    std::cout << G << "Copy assignment operator called" << RST << std::endl;
    return *this;
}

static int detectType(const std::string& literal)
{
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return FLOAT_PSEUDO;
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return DOUBLE_PSEUDO;
	
    if (literal.length() == 1 && !isdigit(literal[0]) && std::isprint(literal[0]))
        return CHAR;
	
    bool isInt = true;
    for (size_t i = 0; i < literal.length(); i++)
    {
        if (i == 0 && (literal[i] == '+' || literal[i] == '-'))
            continue;
        if (!isdigit(literal[i]))
        {
            isInt = false;
            break;
        }
    }
    if(isInt) {
        return INT;
    }

	if (!literal.empty() && literal[literal.length() - 1] == 'f')
	{
		bool hasDot = false;
		for (size_t i = 0; i < literal.length() - 1; i++)
		{
			if (i == 0 && (literal[i] == '+' || literal[i] == '-'))
				continue;
			if (literal[i] == '.')
			{
				if (hasDot)
					return INVALID;
				hasDot = true;
				continue;
			}
			else if (!std::isdigit(literal[i]))
                return INVALID;
		}
		return FLOAT;
	}

	bool hasDot = false;
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (i == 0 && (literal[i] == '+' || literal[i] == '-'))
			continue;
		if (literal[i] == '.')
		{
			if (hasDot)
				return INVALID;
			hasDot = true;
			continue;
		}
		else if (!std::isdigit(literal[i]))
			return INVALID;
	}
	if (hasDot)
		return DOUBLE;

    return INVALID;
}

static void convertChar(const std::string& literal)
{
	char c = literal[0];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void convertNumber(const std::string &literal)
{
	double d = std::strtod(literal.c_str(), NULL);

	if (d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

	if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	std::cout << "float: " << static_cast<float>(d);
	if (d == static_cast<int>(d))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << d;
	if (d == static_cast<int>(d))
		 std::cout << ".0" << std::endl;
}

static void convertPseudo(const std::string &literal)
{
	if (literal[literal.length() - 1] == 'f') // float pseudo
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
	}
	else // double pseudo
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
	}
}

void ScalarConverter::convert(const std::string &literal)
{
    int type = detectType(literal);

    switch (type)
	{
		case CHAR:
			convertChar(literal);
			break;
		case INT:
		case FLOAT:
		case DOUBLE:
			convertNumber(literal);
			break;
		case FLOAT_PSEUDO:
		case DOUBLE_PSEUDO:
			convertPseudo(literal);
			break;
		case INVALID:
			std::cout << R << "Error: Invalid literal." << RST << std::endl;

	}
}