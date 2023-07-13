/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:08:41 by ale-cont          #+#    #+#             */
/*   Updated: 2023/05/25 12:58:32 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cfloat>
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cmath>

static int	checkformat(std::string scalar) {
	int	countdot = 0;
	int	countf = 0;
	if (scalar.size() == 1)
		return 0;
	if (scalar[0] == '-')
		scalar = scalar.substr(1);
	for (int i = 0; scalar[i]; i++) {
		if (scalar[i] == '.')
			countdot++;
		if (scalar[i] == 'f')
			countf++;
		if ((scalar[i] != 'f' && scalar[i] != '.' && !isdigit(scalar[i])) || countdot > 1
			|| (scalar[i] == '.' && scalar[i + 1] && scalar[i + 1] == 'f') || countf > 1
			|| (scalar[i] == 'f' && scalar[i + 1] != '\0')) {
			std::cout << "Please provide a valid literal\n";
			return 1;
		}
	}
	return 0;
}

static int specialtypes(std::string scalar) {
	if (scalar == "nan" || scalar == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (1);
	}
	else if (scalar == "+inf" || scalar == "inf" || scalar == "inff" || scalar == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		return (1);
	}
	else if (scalar == "-inf" || scalar == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return (1);
	}
	else if (scalar[0] == '\0')
	{
		std::cout << "char: Not displayable" << std::endl;
		std::cout << "int: 0" << std::endl;
		std::cout << "float: 0.0f" << std::endl;
		std::cout << "double: 0" << std::endl;
		return (1);
	}
	return (0);
}

int	printchar(std::string scalar) {
	char toChar = scalar[0];
	std::cout << "char: '" << toChar << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(toChar) << std::endl;
	std::cout << "float: " << static_cast<float>(toChar) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(toChar) << ".0" << std::endl;
	return 0;
}

void	printdouble(std::string scalar) {
	double dblvalue = std::strtod(scalar.c_str(), NULL);
	int intValue = static_cast<int>(dblvalue);

	double fractionalPart;
	double integralPart = std::modf(dblvalue, &fractionalPart);

	if (integralPart == 0.0 && dblvalue > 31.0 && dblvalue < 127.0) {
		std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
	} else {
		std::cout << "char: Not displayable" << std::endl;
	}
	if (dblvalue <= 2147483647.0 && dblvalue >= INT_MIN)
		std::cout << "int: " << static_cast<int>(dblvalue) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (dblvalue <= FLT_MAX && dblvalue >= -FLT_MAX)
		std::cout << "float: " << static_cast<float>(dblvalue) << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	if (dblvalue <= DBL_MAX && dblvalue >= -DBL_MAX)
		std::cout << "double: " << static_cast<double>(dblvalue) << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}

void	printfloat(std::string scalar) {
	float floatValue = std::strtof(scalar.c_str(), 0);
	int intValue = static_cast<int>(floatValue);

	float fractionalPart;
	float integralPart = std::modf(floatValue, &fractionalPart);
	if (integralPart == 0.0f && floatValue > 31.0f && floatValue < 127.0f) {
		std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
	} else {
		std::cout << "char: Not displayable" << std::endl;
	}
	if (floatValue <= 2147483647.0f && floatValue >= INT_MIN)
		std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (floatValue <= FLT_MAX && floatValue >= -FLT_MAX)
		std::cout << "float: " << static_cast<float>(floatValue) << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	if (floatValue <= DBL_MAX && floatValue >= -DBL_MAX)
		std::cout << "double: " << static_cast<double>(floatValue) << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}

void	printint(std::string scalar) {
	long	nb;

	nb = std::strtol(scalar.c_str(), NULL, 10);
	if (nb > 31 && nb < 127)
		std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
	else
		std::cout << "char: Not displayable" << std::endl;
	if (nb <= 2147483647 && nb >= INT_MIN)
		std::cout << "int: " << static_cast<int>(nb) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (nb <= FLT_MAX && nb >= -FLT_MAX)
		std::cout << "float: " << static_cast<float>(nb) << ".0f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	if (nb <= DBL_MAX && nb >= -DBL_MAX)
		std::cout << "double: " << static_cast<double>(nb) << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}

void stringToFloatOrDouble(const std::string &str, bool *isFloat)
{
	char *endPtr;
	std::strtof(str.c_str(), &endPtr);
	if (*endPtr != '\0' && *endPtr == 'f') {
		*isFloat = true;
		return ;
	}
	*isFloat = false;
}

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Please provide only one argument like : ./convert 3\n";
		return 1;
	}
	std::string	scalar(av[1]);
	if (specialtypes(scalar))
		return 0;
	if (checkformat(scalar))
		return 1;
	// if it's a char :
	if (scalar.size() == 1 && std::isprint(scalar[0]) && !std::isdigit(scalar[0]))
		return (printchar(scalar));
	// if it's a float or double:
	if (scalar.find(".", 0) != std::string::npos || scalar.find("f", 0) != std::string::npos) {
		bool	isfloat;
		stringToFloatOrDouble(scalar, &isfloat);
		if (isfloat)
			printfloat(scalar);
		else
			printdouble(scalar);
	}
	else
		printint(scalar); // if it's a int
	return (0);
}