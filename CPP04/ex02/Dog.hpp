#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain *brain;

	public:
		Dog();
		Dog( Dog const & src );
		~Dog();

		Dog &				operator=( Dog const & rhs );
		virtual AAnimal &	operator=( AAnimal const & rhs );
		void				makeSound( void ) const;
		Brain				*getBrain( void ) const;
};

#endif