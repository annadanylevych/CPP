#include "iter.hpp"

int main()
{
    std::string  words[3] = {"Word1", "Word2", "sunday"};
    int num[3] = {1, 2 , 3};
    char    letter[3] = {'a', 'b', 'e'};

    ::iter(words, 3, print);
    ::iter(num, 3, print);
    ::iter(letter, 3, print);
}