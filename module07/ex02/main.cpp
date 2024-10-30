#include <iostream>
#include "Array.hpp"
#include "Array.tpp"

int main()
{
    Array<int> nums(4);
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;
    nums[3] = 4;

    for (int i = 0; i <= 6; i++)
        try
        {
            std::cout << nums[i] << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    Array<int> numsi(10);
    numsi = nums;
    std::cout << "NUMSI SIZE:"<< numsi.size() << std::endl;
    for (int i = 0; i <= 6; i++)
        try
        {
            std::cout << numsi[i] << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    Array<std::string> strings(3);
    strings[0] = "Hello World";
    strings[1] = "microplastics";
    strings[2] = "macroplastics";

    std::cout << "STRINGS SIZE:" << strings.size() << std::endl;
    for (unsigned int i = 0; i < strings.size(); i++)
        try 
        {
            std::cout << strings[i] << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

    Array<std::string> words(2);
    words[0] = "Hi";
    words[1] = "bye";

    strings = words;
    std::cout << "NEW STRINGS SIZE:" << strings.size() << std::endl;
    for (unsigned int i = 0; i < strings.size(); i++)
        try 
        {
            std::cout << strings[i] << std::endl;
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

}