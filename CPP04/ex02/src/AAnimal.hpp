#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"
class AAnimal
{
	protected:
		std::string type;

	public:

		AAnimal();
		AAnimal( AAnimal const & src );
		virtual ~AAnimal();

		virtual AAnimal &		operator=( AAnimal const & src ) = 0;
		virtual void			makeSound( void ) const = 0;
		virtual Brain			*getBrain( void ) const = 0;
		std::string				getType( void ) const;
		void					setType(std::string type);
};

#endif