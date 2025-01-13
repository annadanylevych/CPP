#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <map>
#include <vector>
#include <limits>
#include <cmath>


void printMap(const std::map<struct tm, float>& database) {
    for (std::map<struct tm, float>::const_iterator it = database.begin(); it != database.end(); ++it) 
    {
        char buffer[11]; 
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", &it->first);
        std::cout << "Date: " << buffer << ", Rate: " << it->second << std::endl;
    }
}

std::map<tm, float>    parseDB()
{
    std::map<tm, float> data;
    std::ifstream db("data.csv");
    if(!db.is_open())
        throw(std::out_of_range("Database file not valid"));
    std::string line;
    std::getline(db, line);
    if (line != "date,exchange_rate")
        throw(std::invalid_argument("Database cannot be modified"));
    while (std::getline(db, line))
    {
        size_t  comma_pos = line.find(",");
        if (comma_pos == std::string::npos) 
            throw (std::invalid_argument("Comma problem in database occured"));
        std::string date = line.substr(0, comma_pos);
        std::string val = line.substr(comma_pos + 1);
        
         tm date_conv;

         if (!strptime(date.c_str(), "%Y-%m-%d", &date_conv))
             throw(std::invalid_argument("Invalid date format"));
        char *end;
        float val_conv = strtod(val.c_str(), &end);
        if (end == val.c_str() || *end != '\0' || val_conv < 0.0
        || val_conv > std::numeric_limits<float>::max() || std::isnan(val_conv))
            throw(std::invalid_argument("Invalid value"));
        data.insert(std::make_pair(date_conv, val_conv));          
    }
    return (data);
}

bool operator<(const tm& one, const tm& two)
{
    time_t  one_t = std::mktime(const_cast<tm*> (&one));
    time_t  two_t = std::mktime(const_cast<tm*> (&two));

    return (one_t < two_t);
}

bool operator>(const tm& one, const tm& two)
{
    time_t  one_t = std::mktime(const_cast<tm*> (&one));
    time_t  two_t = std::mktime((const_cast<tm*> (&two)));

    return (one_t > two_t);
}

std::map<tm, float> parseInput(std::ifstream& input)
{
    std::map<tm, float> indata;
    if(!input.is_open())
        throw(std::out_of_range("Input file not valid"));
    std::string line;
    std::getline(input, line);
    if (line != "date | value")
        throw(std::invalid_argument("Input file should have a header: date | value"));
    while (std::getline(input, line))
    {
        size_t pipe_pos = line.find("|");
        if (pipe_pos == std::string::npos) 
            throw (std::invalid_argument("Input file error: invalid format"));
        std::string date = line.substr(0, pipe_pos);
        std::string val = line.substr(pipe_pos + 1);
        tm date_conv;

        if (!strptime(date.c_str(), "%Y-%m-%d", &date_conv))
             throw(std::invalid_argument("Invalid date format"));
        char *end;
        float val_conv = strtod(val.c_str(), &end);
        if (end == val.c_str() || *end != '\0' || val_conv < 0.0
        || val_conv > std::numeric_limits<float>::max() || std::isnan(val_conv))
            throw(std::invalid_argument("Invalid value"));
        indata.insert(std::make_pair(date_conv, val_conv));          
    }
    return (indata);
}


void print_values(std::map<tm, float> input, std::map<tm, float> db)
{
    for (std::map<tm, float>::iterator it = input.begin(); it != input.end(); ++it){
        if (db.find(it->first) != db.end()){
            char buffer[11];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d", &it->first);
            std::cout << buffer << " => " << it->second << " = "
                        << it->second * db.at(it->first) << std::endl;
        }
        else {
            std::map<tm, float>::iterator lower_it = db.lower_bound(it->first)
        }
    }
}