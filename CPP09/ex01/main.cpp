#include <iostream>
#include <stack>
#include <vector>

#define CONTAINER std::stack<std::string>

void processStack(CONTAINER &stack, char c)
{
    double first;
    double second;

    second = std::stod(stack.top());
    stack.pop();
    first = std::stod(stack.top());
    stack.pop();
    if (c == '+')
        stack.push(std::to_string(first + second));
    else if (c == '-')
        stack.push(std::to_string(first - second));
    else if (c == '*')
        stack.push(std::to_string(first * second));
    else if (c == '/')
        stack.push(std::to_string(first / second));
    return ;

}

bool isOperation(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isNumber(char c)
{
    return c >= '0' && c <= '9';
}

int send_error(std::string msg, char var = 0)
{
    std::cout << msg << var;
    std::cout << std::endl;
    return -1;
}

int main(int ac, char **av)
{
    CONTAINER stack;
    std::string sent;

    if (ac != 2)
        return(send_error("Error: bad usage:\n- ./RPN ''<calcule>''"));
    for (int i = 0; av[1][i]; i++)
    {
        if (av[1][i] != ' ')
        {
            if (isOperation(av[1][i]))
            {
                if (stack.size() > 1)
                    processStack(stack, av[1][i]);
                else
                    return(send_error("Error: can't compute an operation ", av[1][i]));
            }
            else if (isNumber(av[1][i]))
            {
                while (isNumber(av[1][i]))
                    sent+= av[1][i++];
                i--;
                stack.push(sent);
                sent.clear();
            }
            else
                return(send_error("Error: bad charactere ", av[1][i]));
        }
    }
    while (stack.size())
    {
        std::cout << stack.top() << " | ";
        stack.pop();
    }
}
