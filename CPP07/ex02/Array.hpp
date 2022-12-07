#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>
class Array
{

	public:
		Array<T>() :
		_size(0),
		_content(NULL)
		{
			std::cout << "DEFAULT CONSTRUCTOR" << std::endl;
			return ;
		}

		Array<T>(const unsigned int size) :
		_size(size)
		{
			std::cout << "SIZE CONSTRUCTOR" << std::endl;
			if ((int)size < 0)
				throw std::overflow_error("Size can not be under 0");
			this->_content = new T[this->_size];
			return ;
		}

		Array<T>( Array const & src )
		{
			std::cout << "CPY CONSTRUCTOR" << std::endl;
			this->_size = src._size;
			this->_content = new T[this->getSize()];
			for (int i = 0; i < src._size; i++)
				this->getContent()[i] = src._content[i];
			return ;
		}
		~Array<T>()
		{
			return ;
		}
		Array &		operator=( Array const & rhs )
		{
			if (this->getSize())
				delete [] this->_content;
			this->_size = rhs.getSize();
			this->_content = new T[this->getSize()];
			for (int i = 0; i < rhs.getSize(); i++)
				this->getContent()[i] = rhs.getContent()[i];
			return *this;
		}

		T &			operator[](const int index)
		{
			if (index < 0 || index >= this->getSize())
				throw std::overflow_error("Overflow error");
			else
				return (this->getContent()[index]);
		}
		T *			getContent( void ) const
		{
			return this->_content;
		}
		size_t	getSize( void ) const
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
	for (int k = 0; k < i.getSize(); k++)
	{
		o << "{" << i.getContent()[k] << "} ";
	}
	o << i.getSize() << "]";
	return o;
}

#endif /* *********************************************************** ARRAY_H */