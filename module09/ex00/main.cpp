#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Only 1 argument allowed" << std::endl;
        return(1);
    }
    
    std::string filename = argv[1];
    std::ifstream input(filename)
}