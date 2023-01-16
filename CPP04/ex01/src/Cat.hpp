#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat( Cat const & src );
		~Cat();

		Cat &					operator=( Cat const & rhs );
		virtual Animal &		operator=( Animal const & rhs );
		void					makeSound( void ) const;
		Brain					*getBrain( void ) const;
};

#endif