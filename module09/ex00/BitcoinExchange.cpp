#include "BitcoinExchange.hpp"


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
        std::memset(&date_conv, 0, sizeof(tm));
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

void parseInput(std::ifstream& input, std::map<tm, float> db)
{
    if(!input.is_open())
        throw(std::out_of_range("Input file not valid"));
    
    std::string line;
    bool is_first_line = true;

    while (std::getline(input, line)) {
        line.erase(0, line.find_first_not_of(" \t"));
        line.erase(line.find_last_not_of(" \t") + 1);

        if (line.empty())
            continue;

        if (is_first_line) {
            is_first_line = false;
            if (line.find("|") != std::string::npos) {
                size_t pipe_pos = line.find("|");
                std::string left = line.substr(0, pipe_pos);
                std::string right = line.substr(pipe_pos + 1);
                if (!std::isdigit(left[0]) && !std::isdigit(right[0])) {
                    continue;
                }
            }
        }

        size_t pipe_pos = line.find("|");
        if (pipe_pos == std::string::npos){
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pipe_pos);
        std::string val = line.substr(pipe_pos + 1);

        tm date_conv;
        std::memset(&date_conv, 0, sizeof(tm));
        if (!strptime(date.c_str(), "%Y-%m-%d", &date_conv)){
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
    
        char *end;
        float val_conv = strtod(val.c_str(), &end);
        if (end == val.c_str() || std::isnan(val_conv) || *end != '\0'){
            std::cout << "Error: invalid number" << std::endl;
            continue;
        }
        else if (val_conv < 0.0){
            std::cout << "Error: negative number" << std::endl;
            continue;
        }
        else if (val_conv > 1000){
            std::cout << "Error: too large a number" << std::endl;
            continue;
        }
        else if (db.find(date_conv) != db.end()){
            char buffer[11];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d", &date_conv);
            std::cout << buffer << " => " << val_conv << " = "
                        << val_conv * db.at(date_conv) << std::endl;
        }
        else {
            std::map<tm, float>::iterator closest_it = db.end();
            for (std::map<tm, float>::iterator db_it = db.begin(); db_it != db.end(); db_it++){
                if (db_it->first < date_conv){
                    if (closest_it == db.end() || closest_it->first < db_it->first)
                        closest_it = db_it;
                }
            }
            if (closest_it != db.end())
            {
                char buffer[11];
                strftime(buffer, sizeof(buffer), "%Y-%m-%d", &date_conv);
                std::cout << buffer << " => " << val_conv << " = "
                        << val_conv * closest_it->second << std::endl;
            }
            else {
                char buffer[11];
                strftime(buffer, sizeof(buffer), "%Y-%m-%d", &date_conv);
                std::cerr << "Error: No valid date in database for " << buffer << std::endl;
            }
        }
    }
}
