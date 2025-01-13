#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
        throw (std::out_of_range("Only 1 argument allowed"));
    std::ifstream input(argv[1]);
    try
    {
        std::map<tm, float> database;
        std::map<tm, float> inputMap;
        database = parseDB();
        inputMap = parseInput(input);
        printMap(inputMap);
        //print_values(inputMap, database);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return(0);
}