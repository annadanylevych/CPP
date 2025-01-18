#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2){
        std::cerr << "Error: 2 arguments are required" << std::endl;
        return (1);
    }
    try
    {
        std::vector<std::string> parsedNums = parseNumbers(argv[1]);
        int result = operate(parsedNums);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}