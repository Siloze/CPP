#include "MultiType.hpp"

MultiType::MultiType()
{
	return ;
}

MultiType::MultiType(char *input) :
_int_value(0),
_float_value(0.1f),
_double_value(0.1f),
_char_value(0),
selected_value("")
{
	setSelectedValue((char *)check_special(input).c_str());
	if (this->getSelectedValue() == "INT")
		this->setAllValueFromInt(atoi(input));
	else if (this->getSelectedValue() == "FLOAT")
		this->setAllValueFromFloat(atof(input));
	else if (this->getSelectedValue() == "DOUBLE")
		this->setAllValueFromDouble(atof(input));
	else if (this->getSelectedValue() == "CHAR")
		this->setAllValueFromChar(input[0]);
}

MultiType::MultiType( const MultiType & src )
{
	return ;
}

MultiType::~MultiType()
{
}

MultiType &				MultiType::operator=( MultiType const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, MultiType const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}

void					MultiType::setCharValue (char value)
{
	this->_char_value = value;
	return ;
}

void					MultiType::setIntValue (int value)
{
	this->_int_value = value;
	return ;
}

void					MultiType::setFloatValue (float value)
{
	this->_float_value = value;
	return ;
}

void					MultiType::setDoubleValue (double value)
{
	this->_double_value = value;
	return ;
}

void					MultiType::setSelectedValue (char *value)
{
	if (is_int(value))
		selected_value = "INT";
	else if (is_float(value))
		selected_value = "FLOAT";
	else if (is_double(value))
		selected_value = "DOUBLE";
	else if (is_char(value))
		selected_value = "CHAR";
	else
		selected_value = value;
	std::cout << "selected value : " << selected_value << std::endl;
	return ;
}

std::string				MultiType::getSelectedValue ( void ) const
{
	return (this->selected_value);
}

void					MultiType::setAllValueFromInt(int value)
{
	this->setIntValue(value);
	this->setFloatValue(static_cast<float>(value));
	this->setDoubleValue(static_cast<double>(value));
	this->setCharValue(value);
}

void					MultiType::setAllValueFromFloat(float value)
{
	this->setIntValue(static_cast<int>(value));
	this->setFloatValue(value);
	this->setDoubleValue(static_cast<double>(value));
	this->setCharValue(static_cast<char>(value));
}

void					MultiType::setAllValueFromDouble(double value)
{
	this->setIntValue(static_cast<int>(value));
	this->setFloatValue(static_cast<float>(value));
	this->setDoubleValue(value);
	this->setCharValue(static_cast<char>(value));
}

void					MultiType::setAllValueFromChar(char value)
{
	this->setIntValue(static_cast<int>(value));
	this->setFloatValue(static_cast<float>(value));
	this->setDoubleValue(static_cast<double>(value));
	this->setCharValue(value);
}

void				MultiType::showAllValue( void ) const
{
	if (CanConvertToInt(this->_double_value) && this->getSelectedValue() != "inf" && this->getSelectedValue() != "nan")
		std::cout << "Int : " << this->_int_value << std::endl;
	else
		std::cout << "Int : " << "Impossible" << std::endl;
	if (CanConvertToFloat(this->_double_value))
	{
		std::cout << "Float : " << this->_float_value;
		if (this->_float_value == this->_int_value)
			std::cout << ".00";
		std::cout << "f" << std::endl;
	}
	else if (this->getSelectedValue() == "nan")
		std::cout << "Float : " << "nanf" << std::endl;
	else if (this->getSelectedValue() == "inf")
		std::cout << "Float : " << "inff" << std::endl;
	else
		std::cout << "Float : Impossible" << std::endl;
	if (this->getSelectedValue() == "nan")
		std::cout << "Double : " << "nan" << std::endl;
	else if (this->getSelectedValue() == "inf")
		std::cout << "Double : " << "inf" << std::endl;
	else
	{
		std::cout << "Double : " << this->_double_value;
		if (this->_double_value == this->_int_value)
			std::cout << ".00";
		std::cout << std::endl;
	}
	if (CanConvertToChar(this->_double_value) && this->getSelectedValue() != "inf" && this->getSelectedValue() != "nan")
		std::cout << "Char : " << this->_char_value << std::endl;
	else
		std::cout << "Char : " << "Non displayable" << std::endl;

}
/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */