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
	for (size_t j = 0; j < strlen(nb); j++)
	{
		if (nb[j] == '.')
			i++;
		if (i > 0)
			return false;
	}

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
	if (isprint(nb))
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
	if (nb >= -340282346638528859811704183484516925440.0000000000000000 && nb <= 340282346638528859811704183484516925440.0000000000000000)
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
	if (nb[0] != 'f' && is_numeric(nb, 1) && CanConvertToFloat(atof(nb)))
		return true;
	return false;
}

bool    is_double( char *nb )
{
	if (strchr(nb, 'f'))
		return false;
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

	if (line == "+inff" || line == "+inf" || line == "inf" || line == "inff")
		return ("inf");
	else if (line == "-inff" || line == "-inf")
		return ("-inf");
	else if (line == "nan" || line == "nanf")
		return ("nan");
	return (input);
}

bool	is_valid( char *input )
{
	std::string line(input);
	if (line == "nan" || line == "nanf" || line == "-inff" || line == "+inff" || line == "+inf" || line == "-inf" || line == "inf" || line == "inff")
		return true;
	if (is_int(input) || is_float(input) || is_double(input) || is_char(input))
		return true;
	return false;
}