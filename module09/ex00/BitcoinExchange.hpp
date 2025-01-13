#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <map>
#include <vector>
#include <limits>
#include <cmath>

void printMap(const std::map<struct tm, float>& database);
std::map<tm, float>    parseDB();
void parseInput(std::ifstream& input, std::map<tm, float> db);
bool operator<(const tm& one, const tm& two);
bool operator>(const tm& one, const tm& two);
