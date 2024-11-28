#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
        throw (std::out_of_range("Only 1 argument allowed"));
    (void)argv;
    try
    {
        std::map<tm, float> database;
        database = parseDB();
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return(0);
}