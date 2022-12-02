#include "Base.hpp"
#include <iostream>

class A : public Base{
};

class B : public Base{
};

class C : public Base{
};

Base * generate(void)
{
    Base *ptr;
   	srand(time(0));
    switch ( rand() % 3)
    {
        case 0:
            std::cout << "A CONSTRUCT" << std::endl;
            ptr = new A();
            break;
        case 1:
            std::cout << "B CONSTRUCT" << std::endl;
            ptr = new B();
            break;
        case 2:
            std::cout << "C CONSTRUCT" << std::endl;
            ptr = new C();
            break;
    }
    return ptr;
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "POINTER IS A TYPE" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "POINTER IS B TYPE" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "POINTER IS C TYPE" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "REFERENCE IS A TYPE" << std::endl;
    }
    catch(const std::bad_cast& e)
    {
        (void)e;
    }
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "REFERENCE IS B TYPE" << std::endl;
    }
    catch(const std::bad_cast& e)
    {
        (void)e;
    }
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "REFERENCE IS C TYPE" << std::endl;
    }
    catch(const std::bad_cast& e)
    {
        (void)e;
    }
    
}

int main(void)
{
    Base *ptr;

    ptr = generate();
    identify(ptr);
    delete ptr;
    ptr = generate();
    Base &ref = *ptr;
    identify(ref);
    delete ptr;
    return 1;
}