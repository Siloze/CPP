#ifndef MULTITYPE_HPP
# define MULTITYPE_HPP

# include <iostream>
# include <string>

bool	ft_isdigit( char c );
bool    is_numeric( char *nb );
bool    is_int( char *nb );
bool    is_float( char *nb );
bool    is_double( char *nb );
bool    is_char( char *nb );
bool	CanConvertToChar ( double nb );
bool	CanConvertToInt ( double nb );
bool	CanConvertToFloat ( double nb );
std::string check_special( char *input );

class MultiType
{

	public:

		MultiType();
		MultiType(char *input);
		MultiType( MultiType const & src );
		~MultiType();

		MultiType &		operator=( MultiType const & rhs );
		void setIntValue(int value);
		void setFloatValue(float value);
		void setDoubleValue(double value);
		void setCharValue(char value);
		void setSelectedValue(char *value);

		void setAllValueFromInt(int value);
		void setAllValueFromFloat(float value);
		void setAllValueFromDouble(double value);
		void setAllValueFromChar(char value);

		void showAllValue(void) const;
		std::string getSelectedValue(void) const;
	private:

		std::string selected_value;
		int _int_value;
		float _float_value;
		double _double_value;
		char _char_value;
		bool is_infinite;
		bool is_nan;

};

std::ostream &			operator<<( std::ostream & o, MultiType const & i );

#endif /* ******************************************************* MULTITYPE_H */