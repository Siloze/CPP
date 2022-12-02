#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat( Cat const & src );
		~Cat();

		Cat &					operator=( Cat const & rhs );
		virtual AAnimal &		operator=( AAnimal const & rhs );
		void					makeSound( void ) const;
		Brain					*getBrain( void ) const;
};

#endif