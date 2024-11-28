#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <map>
#include <vector>

void    parseDB()
{
    std::map<tm, float> data;
    std::ifstream db("data.csv");
    if(!db.is_open())
        throw(std::out_of_range("Database file not valid"));
    std::string line;
    std::getline(db, line);
    if (line != "date,exchange_rate")
        throw(std::invalid_argument("Database cannot be modified"));
    while (std::getline(db, line, ','))
    {
        
    }
 
}

std::vector<std::string> split(const std::string& str, char delimiter)
{

}