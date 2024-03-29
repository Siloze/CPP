#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span():
_max(0)
{
	return ;
}

Span::Span(const unsigned int n):
_max(n)
{
	return ;
}


Span::Span( const Span & src ):
_max(src._max)
{
	this->_content = src._content;
	return;
}


Span::~Span()
{
	return ;
}

Span &				Span::operator=( Span const & rhs )
{
	this->_content = rhs._content;
	this->_max = rhs._max;
	return *this;
}

int & 				Span::access(const unsigned int index) const
{
	if (index >= this->_content.size())
		throw std::overflow_error("Acces Index too high !");	
	std::list<int>::const_iterator it = this->_content.begin();
	std::advance(it, index);
	return (const_cast<int &>(*it));
}

int					Span::shortestSpan( void )
{
	if (this->getSize() <= 1)
		throw std::length_error("Span::shortestSpan Not any values.");
	int distance =  std::numeric_limits<int>::max();
	int value;

	for (unsigned int i = 0; i < this->getSize(); i++)
	{
		for (unsigned int k = 0; k < this->getSize(); k++)
		{
			value = this->access(i) - this->access(k);
			if (i != k && (value < distance && value >= 0))
				distance = value;
		}
	}
	return distance;
}

int					Span::longestSpan( void )
{
	if (this->getSize() <= 1)
		throw std::length_error("Span::longestSpan Not any values.");
	int distance = 0;
	int value;

	for (unsigned int i = 0; i < this->getSize(); i++)
	{
		for (unsigned int k = 0; k < this->getSize(); k++)
		{
			value = this->access(i) - this->access(k);
			if (i != k && (value > distance && value >= 0))
				distance = value;
		}
	}
	return distance;
}

void				Span::addNumber( int nb )
{
	if (this->getSize() < this->_max)
		this->_content.push_back(nb);
	else
		throw std::length_error("Span::AddNumber : Trying to add element to an Span with max elements !");
	return ;
}

unsigned int Span::getSize( void ) const
{
	return this->_content.size();
}

std::ostream &			operator<<( std::ostream & o, Span const & i )
{
	o << "[Size: " << i.getSize() << " {";
	for (unsigned int k = 0; k < i.getSize(); k++)
	{
		o << i.access(k) << "";
		if (k != i.getSize() - 1)
			o << ", ";
	}
	o << "}]" << std::endl;
	return o;
}

void		Span::fillByIterator(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	if (this->getSize() + std::distance(begin, end) > this->_max)
		throw std::length_error("Span::fillByIterator : Trying to add element(s) to an Span with max elements !");
	else
		this->_content.insert(this->_content.end(), begin, end);
	return ;
}
