#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{
    public:
        Fixed(void);
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &src);
        ~Fixed(void);

        Fixed &operator=(const Fixed &rhs);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

    private:
        int                 _value;
        static const int    _bits = 8;
};

#endif