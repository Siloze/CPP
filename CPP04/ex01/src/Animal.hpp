#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"
class Animal
{
	protected:
		std::string type;

	public:

		Animal();
		Animal( Animal const & src );
		virtual ~Animal();

		virtual Animal &		operator=( Animal const & src );
		virtual void			makeSound( void ) const;
		virtual Brain			*getBrain( void ) const = 0;
		std::string				getType( void ) const;
		void					setType(std::string type);
};

#endif