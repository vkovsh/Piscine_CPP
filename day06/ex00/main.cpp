#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <string.h>
#include <cmath>
#include <iomanip> 

bool		isDigit(char d) {
	if (d >= '0' && d <= '9')
		return true;
	return false;
}

bool		isPrintable(char c) {
	if (c >= 32 && c <= 126)
		return true;
	return false;
}

int	getPrecision(char *data) {
	int length = static_cast<int>(strlen(data));
	bool dot_set = false;
	int i = 0;
	int precision = 0;
	if (data[i] == '-' || data[i] == '+') {
		i++;
	}
	while (i < length) {
		if (isDigit(data[i])) {
			precision += dot_set;
		}
		else if (data[i] == '.') {
			if (!dot_set) {
				dot_set = true;
			}
			else {
				return precision;
			}
		}
		else {
			return precision;
		}
		i++;
	}
	return precision;
}

char	toChar(double value) {
	if (value < 0 || value > 127)
		return -1;
	char result = static_cast<char>(value);
	return result;
}

void	printChar(double value) {
	if (std::isnan(value) ||std::isinf(value)) {
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	char charRes = toChar(value);
	if (isPrintable(charRes)) {
		std::cout << "char: '"<< charRes << "'" << std::endl;
	}
	else {
		std::cout << "char: Non displayable" << std::endl;
	}
}

int		toInt(double value) {
	int result = static_cast<int>(value);
	return result;
}

void	printInt(double value) {
	if (std::isnan(value) ||std::isinf(value)) {
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	int intRes = toInt(value);
	std::cout << "int: "<< intRes << std::endl;
}

void	printFloat(double value, int precision) {
	precision += (precision) ? 0 : 1;
	float floatRes = static_cast<float>(value);
	std::cout << "float: " << std::setprecision(precision) << std::fixed <<floatRes << "f" << std::endl;
}

void	printDouble(double value, int precision) {
	precision += (precision) ? 0 : 1;
	std::cout << "double: " << std::setprecision(precision) <<  std::fixed << value << std::endl;
}

int	main(int ac, char **av)
{
	double value;
	int precision;
	for (int i = 1; i < ac; ++i) {
		precision = getPrecision(av[i]);
		if (strlen(av[i]) == 1 && isPrintable(av[i][0]) && !isdigit(av[i][0])) {
			value = av[i][0];
		}
		else {
			value = atof(av[i]);
		}
		printChar(value);
		printInt(value);
		printFloat(value, precision);
		printDouble(value, precision);
	}
	return 0;
}