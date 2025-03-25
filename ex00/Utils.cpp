#include "ScalarConverter.h"
#include "Utils.h"

static int	isInt(const std::string&str)
{
	int i = 0;
	size_t len = str.length();
	bool flag = false;

	if (str[0] == '-' || str[0] == '+')
	{
		flag = true;
		++i;
	}
	for (int i = 0; (str[i] && len > 0 && len < 12) || (str[i] && !flag && len > 0 && len < 11); ++i)
	{
		if (!isdigit(str[i]))
			return 0;
	}
	return 1;
}

static int	isFloat(const std::string&str, size_t&dot)
{
	size_t len = str.length();
	
	for (int j = dot - 1; j >= 0; j--)
	{
		if (!isdigit(str[j]) && j != 0)
			return 0;
		if (!isdigit(str[j]) && j == 0 && str[j] != '+' && str[j] != '-')
			return 0;
	}
	for (size_t i = dot + 1; i < len; i++)
	{
		if (!isdigit(str[i]) && str[i] != 'f')
			return 0;
		if (str[i] == 'f' && i != len - 1)
			return 0;
	}
	return 1;
}

ScalarTypes Utils::getType(const std::string&str)
{
	size_t len = str.length();
    size_t dot = str.find('.');
    size_t f = str.find('f');
    if (dot == std::string::npos)
    {
        if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
            return SPECIAL;
        if ((len == 1 && !isdigit(str[0])) || (len == 3 && str[0] == '\'' && str[2] == '\''))
            return CHAR;
        if (isInt(str))
            return INT;
    }
    if (f != std::string::npos && dot != std::string::npos)
    {
        if (isFloat(str, dot))
        	return FLOAT;
    }
    else if (f == std::string::npos && dot != std::string::npos)
        return DOUBLE;
    return INVALID;
}


void Utils::convertSpecial(const std::string&str) {
	if (str == "nan" || str == "nanf")
	{
		// CHAR //
		std::cout << CYAN "char: " RED "impossible" RESET << std::endl; 
		// INT //
		std::cout << CYAN "int: " RED "impossible" RESET << std::endl;
		// FLOAT //
		std::cout << CYAN "float: " GREEN "nanf" << std::endl;
		// DOUBLE //
		std::cout << CYAN "double: " GREEN "nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		// CHAR //
		std::cout << CYAN "char: " RED "impossible" RESET << std::endl;
		// INT //
		std::cout << CYAN "int: " RED "impossible" RESET << std::endl;
		// FLOAT //
		std::cout << CYAN "float: " GREEN "+inff" RESET << std::endl;
		// DOUBLE //
		std::cout << CYAN "double: " GREEN "+inf" RESET << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		// CHAR //
		std::cout << CYAN "char: " RED "impossible" RESET << std::endl;
		// INT //
		std::cout << CYAN "int: " RED "impossible" RESET << std::endl;
		// FLOAT //
		std::cout << CYAN "float: " GREEN "-inff" RESET << std::endl;
		// DOUBLE //
		std::cout << CYAN "double: " GREEN "-inf" RESET << std::endl;
	}
}

void Utils::convertChar(const std::string&str) {
    size_t len = str.length();
	char	c = 0;

	if (len == 1)
		c = str[0];
	else
		c = str[1];

	// CHAR //
	if (isprint(c))
		std::cout << CYAN "char: " GREEN "'" << c << "'" RESET << std::endl;
	else
		std::cout << CYAN "char: " RED "non displayable" RESET << std::endl;
	
	// INT //
	std::cout << CYAN "int: " GREEN << static_cast<int>(c) << RESET << std::endl;
	
	// FLOAT //
	std::cout << CYAN "float: " GREEN << static_cast<float>(c) << ".0f" RESET << std::endl;

	// DOUBLE //
	std::cout << CYAN "double: " GREEN << static_cast<double>(c) << ".0" RESET << std::endl;
}

void Utils::convertInt(const std::string&str) {
	long	l = std::atol(str.c_str());

	// CHAR //
	std::cout << CYAN "char: ";
	if (l < 0 || l > 127)
		std::cout << RED "impossible" RESET << std::endl;
	else
	{
		if (isprint(l))
			std::cout << GREEN "'" << static_cast<char>(l) << "'" RESET << std::endl;
		else
			std::cout << RED "non displayable" RESET << std::endl;
	}

	// INT //
	std::cout << CYAN "int: ";
	if (l < MIN_INT || l > MAX_INT)
		std::cout << RED "impossible" RESET << std::endl;
	else
		std::cout << GREEN << static_cast<int>(l) << RESET << std::endl;

	// FLOAT //
	std::cout << CYAN "float: " GREEN << static_cast<float>(l) << ".0f" RESET << std::endl;

	// DOUBLE //
	std::cout << CYAN "double: " GREEN << static_cast<double>(l) << ".0" RESET << std::endl;
}

void Utils::convertFloat(const std::string&str) {
    float	f = std::atof(str.c_str());
	bool	tolerance = std::fabs(f - static_cast<int>(f)) < 0.0000000000001;

	// CHAR //
	std::cout << CYAN "char: ";
	if (f < 0 || f > 127)
		std::cout << RED "impossible" RESET << std::endl;
	else
	{
		if (isprint(f))
			std::cout << GREEN "'" << static_cast<char>(f) << "'" RESET << std::endl;
		else 
			std::cout << RED "non displayable" RESET << std::endl;
	}

	// INT //
	std::cout << CYAN "int: ";
	if (static_cast<long>(f) < MIN_INT || static_cast<long>(f) > MAX_INT)
		std::cout << RED "impossible" RESET << std::endl;
	else
		std::cout << GREEN << static_cast<int>(f) << RESET << std::endl;
	
	// FLOAT //
	std::cout << CYAN "float: ";
	if (f < MIN_FLOAT || f > MAX_FLOAT)
		std::cout << RED "impossible" RESET << std::endl;
	else
		std::cout << GREEN << f << (tolerance ? ".0f" : "f") << RESET << std::endl;

	// DOUBLE //
	std::cout << CYAN "double: " << GREEN << static_cast<double>(f) << (tolerance ? ".0" : "") << RESET << std::endl;
}

void Utils::convertDouble(const std::string&str) {
    double		d = std::atof(str.c_str());
	bool		tolerance = std::fabs(d - static_cast<int>(d)) < 0.0000000000001;

	// CHAR //
	std::cout << CYAN "char: ";
	if (d < 0 || d > 127)
		std::cout << RED "impossible" RESET << std::endl;
	else
	{
		if (isprint(d))
			std::cout << GREEN "'" << static_cast<char>(d) << "'" RESET << std::endl;
		else 
			std::cout << RED "non displayable" RESET << std::endl;
	}

	// INT //
	std::cout << CYAN "int: ";
	if (d < MIN_INT || d > MAX_INT)
		std::cout << RED "impossible" RESET << std::endl;
	else
		std::cout << GREEN << static_cast<int>(d) << RESET << std::endl;

	// FLOAT //
	std::cout << CYAN "float: ";
	if (d < MIN_FLOAT || d > MAX_FLOAT)
		std::cout << RED "impossible" RESET << std::endl;
	else
		std::cout << GREEN << static_cast<float>(d) << (tolerance ? ".0f" : "f") << RESET << std::endl;

	// DOUBLE //
	std::cout << CYAN "double: ";
	if (d < MIN_DOUBLE || d > MAX_DOUBLE)
		std::cout << RED "impossible" RESET << std::endl;
	else
		std::cout << GREEN << d << RESET << std::endl;
}

void Utils::printInvalid(const std::string&str) {
	(void)str;
	std::cout << RED << "invalid input!" << RESET << std::endl;
}

void (*Utils::converters[6])(const std::string&) = {
	Utils::printInvalid,
	Utils::convertSpecial, 
	Utils::convertChar,
	Utils::convertInt,
	Utils::convertFloat,
	Utils::convertDouble
};