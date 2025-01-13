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
        if (pipe_pos == std::string::npos){
            tm date_conv;
            std::memset(&date_conv, -1, sizeof(tm));
            float val_conv = INVALID;
            indata.insert(std::make_pair(date_conv, val_conv));          
            continue;
        }
        std::string date = line.substr(0, pipe_pos);
        std::string val = line.substr(pipe_pos + 1);
        tm date_conv;
        std::memset(&date_conv, 0, sizeof(tm));
        strptime(date.c_str(), "%Y-%m-%d", &date_conv);
        char *end;
        float val_conv = strtod(val.c_str(), &end);
        if (end == val.c_str() || std::isnan(val_conv) || *end != '\0')
            val_conv = INVALID;
        else if (val_conv < 0.0)
            val_conv = NEGATIVE;
        else if (val_conv > std::numeric_limits<float>::max())
            val_conv = TOO_LARGE;
        indata.insert(std::make_pair(date_conv, val_conv));        
        char buffer[11]; 
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", &date_conv);
        std::cout << "Date: " << buffer << ", Rate: " << val_conv << std::endl;
    }
    return (indata);
}


void print_values(std::map<tm, float> input, std::map<tm, float> db)
{
    tm invalid_date;
    std::memset(&invalid_date, -1, sizeof(tm));
    for (std::map<tm, float>::iterator it = input.begin(); it != input.end(); ++it){
        if (std::memcmp(&it->first, &invalid_date, sizeof(tm)) == 0)
            std::cout << "Error: invalid date" << std::endl;
        else if (it->second == NEGATIVE)
            std::cout << "Error: negative value" << std::endl;
        else if (it->second == TOO_LARGE)
            std::cout << "Error: number too big" << std::endl;
        else if (it->second == INVALID)
            std::cout << "Error: invalid number" << std::endl;
        else if (db.find(it->first) != db.end()){
            char buffer[11];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d", &it->first);
            std::cout << buffer << " => " << it->second << " = "
                        << it->second * db.at(it->first) << std::endl;
        }
        else {
            std::map<tm, float>::iterator closest_it = db.end();
            for (std::map<tm, float>::iterator db_it = db.begin(); db_it != db.end(); db_it++){
                if (db_it->first < it->first){
                    if (closest_it == db.end() || closest_it->first < db_it->first)
                        closest_it = db_it;
                }
            }
            if (closest_it != db.end())
            {
                char buffer[11];
                strftime(buffer, sizeof(buffer), "%Y-%m-%d", &it->first);
                std::cout << buffer << " => " << it->second << " = "
                        << it->second * closest_it->second << std::endl;
            }
            else {
                char buffer[11];
                strftime(buffer, sizeof(buffer), "%Y-%m-%d", &it->first);
                std::cerr << "Error: No valid date in database for " << buffer << std::endl;
            }
        }
    }
}