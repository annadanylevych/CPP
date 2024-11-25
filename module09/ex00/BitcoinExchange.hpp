#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <map>
#include <vector>

void    parseDB()
{
    std::ifstream db("data.csv");
    if(!db.is_open())
        throw(std::"")
    std::string line;
    while(std::getline(db, line))
    {
        
    }
}

std::vector<std::string> split(const std::string& str, char delimiter)