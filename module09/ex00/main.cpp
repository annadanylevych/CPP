#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        throw (std::out_of_range("Only 1 argument allowed"));
    
    std::string filename = argv[1];
    std::ifstream input(filename)
}