#include "stdio.h"
#include <iostream>

bool	ft_isdigit( char c )
{
	return (c >= '0' && c <= '9');
}

bool    is_numeric( char *nb , int is_float)
{
	int i;

	i = -1;
	if (nb[0] == '-' || nb[1] == '+')
		i++;
	while (ft_isdigit(nb[++i]) || (nb[i] == '.' && i != 0 && is_float) || (nb[i] == 'f' && !nb[i + 1] && is_float))
		if (!nb[i + 1])
			return true;
	return false;
}

bool	CanConvertToChar ( double nb )
{
	if (nb >= 0 && nb <= 127)
		return true;
	return false;
}


bool	CanConvertToInt ( double nb )
{
	if (nb <= std::numeric_limits<int>::max() && nb >= std::numeric_limits<int>::min())
		return true;
	return false;
}

bool	CanConvertToFloat ( double nb )
{
	if (nb <= std::numeric_limits<float>::max() && nb >= std::numeric_limits<float>::min())
		return true;
	return false;
}


bool    is_int( char *nb )
{
	if (is_numeric(nb, 0) && CanConvertToInt(atof(nb)))
		return true;
	return false;
}

bool    is_float( char *nb )
{
	if (is_numeric(nb, 1) && CanConvertToFloat(atof(nb)))
		return true;
	return false;
}

bool    is_double( char *nb )
{
	if (is_numeric(nb, 1))
		return true;
	return false;
}

bool    is_char( char *nb )
{
	if (strlen(nb) == 1 && !ft_isdigit(nb[0]))
		return (true);
	else if (is_numeric(nb, 0) && CanConvertToChar(atof(nb)))
		return (true);
	return false;
}

std::string check_special( char *input )
{
	std::string line(input);

	if (line == "-inff" || line == "+inff" || line == "+inf" || line == "-inf")
		return ("inf");
	else if (line == "nan" || line == "nanf")
		return ("nan");
	return (input);
}