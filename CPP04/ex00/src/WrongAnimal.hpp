#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string type;

	public:

		WrongAnimal();
		WrongAnimal( WrongAnimal const & src );
		~WrongAnimal();

		WrongAnimal &		operator=( WrongAnimal const & src );

		void	makeSound( void ) const;
		std::string		getType( void ) const;
		void			setType(std::string type);
};

#endif