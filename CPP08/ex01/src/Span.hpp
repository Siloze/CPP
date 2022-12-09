#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <list>

class Span
{

	public:

		Span();
		Span(const unsigned int n);
		Span( Span const & src );
		~Span();

		Span &		operator=( Span const & rhs );
		int	&		access(const unsigned int nb);
		void 		addNumber( int nb );
		unsigned int	getSize( void ) const;
		int			shortestSpan( void ); 
		int			longestSpan( void );
		void		fillByIterator(std::list<int>::iterator begin, std::list<int>::iterator end);
	private:
		std::list<int>		_content;
		unsigned int	_max;

};

std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */