#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "Date.hpp"

#define CONTAINER std::vector<std::pair<Date, std::string> >

bool isDateValid(std::string &date);
