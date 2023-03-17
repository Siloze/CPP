#include "RPN.hpp"

bool isOperation(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isNumber(char c)
{
    return c >= '0' && c <= '9';
}

int send_error(std::string msg, char var)
{
    std::cout << msg << var;
    std::cout << std::endl;
    return -1;
}