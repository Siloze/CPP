#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	public :
		Fixed (void);
		Fixed (int const nb);
		Fixed (Fixed const &src);
		~Fixed(void);

		Fixed & operator=(Fixed const &src);
		int getRawBits( void ) const;
		void setRawBits( int const raw);

	private	:
		int value;
		const static int bits_fractionary;
};


#endif