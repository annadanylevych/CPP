#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cmath>
#include <stack>
#include <sstream>

std::vector<std::string> parseNumbers(std::string numbers);
int    operate(std::vector<std::string> parsedNums);
int calculate(int num1, int num2, char op);
