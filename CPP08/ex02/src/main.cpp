#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	MutantStack<int> mystack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	mystack = mstack;
	MutantStack<int>::iterator it = mystack.begin();
	MutantStack<int>::iterator ite = mystack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}