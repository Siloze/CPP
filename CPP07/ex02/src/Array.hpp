#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>
class Array
{

	public:
		Array<T>() :
		_content(NULL),
		_size(0)
		{
			std::cout << "DEFAULT CONSTRUCTOR" << std::endl;
			return ;
		}

		Array<T>(const unsigned int size)
		{
			std::cout << "SIZE CONSTRUCTOR" << std::endl;
			if ((int)size < 0)
				throw std::overflow_error("Size can not be under 0");
			this->_size = size;
			this->_content = new T[this->_size];
			return ;
		}

		Array<T>( Array const & src )
		{
			std::cout << "CPY CONSTRUCTOR" << std::endl;
			this->_size = src._size;
			this->_content = new T[this->size()];
			for (size_t i = 0; i < src._size; i++)
				this->getContent()[i] = src._content[i];
			return ;
		}
		~Array<T>()
		{
			return ;
		}
		Array &		operator=( Array const & rhs )
		{
			if (this->size())
				delete [] this->_content;
			this->_size = rhs.size();
			this->_content = new T[this->size()];
			for (size_t i = 0; i < rhs.size(); i++)
				this->getContent()[i] = rhs.getContent()[i];
			return *this;
		}

		T &			operator[](const int index)
		{
			if (index < 0 || index >= (int)this->size())
				throw std::overflow_error("Overflow error");
			else
				return (this->getContent()[index]);
		}
		T *			getContent( void ) const
		{
			return this->_content;
		}
		size_t	size( void ) const
		{
			return this->_size;
		}
	private:
		T*		_content;
		size_t	_size;

};

template<typename T>
std::ostream &			operator<<( std::ostream & o, Array<T> const & i )
{
	o << "[ ";
	for (size_t k = 0; k < i.size(); k++)
	{
		o << "{" << i.getContent()[k] << "} ";
	}
	o << i.size() << "]";
	return o;
}

#endif /* *********************************************************** ARRAY_H */