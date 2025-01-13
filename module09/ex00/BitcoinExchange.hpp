#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <map>
#include <vector>
#include <limits>
#include <cmath>

#define TOO_LARGE -3.0f
#define NEGATIVE -1.0
#define INVALID -2.0


void printMap(const std::map<struct tm, float>& database);
std::map<tm, float>    parseDB();
std::map<tm, float> parseInput(std::ifstream& input);
void print_values(std::map<tm, float> input, std::map<tm, float> db);
