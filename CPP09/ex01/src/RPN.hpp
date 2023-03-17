#pragma once

#include <iostream>
#include <stack>
#include <vector>

int send_error(std::string msg, char var = 0);
bool isNumber(char c);
bool isOperation(char c);