#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack(void) : std::stack<T>() {return ;}
        MutantStack(const MutantStack &src) : std::stack<T>(src) {return ;}
        ~MutantStack(void) {return ;}
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin(void) { 
            return ( this->c.begin()); 
        }
        iterator end(void) {
             return ( this->c.end()); 
        }
        MutantStack &operator=(const MutantStack &rhs) {
            std::stack<T>::operator=(rhs);
            return (*this);
        }
};


#endif