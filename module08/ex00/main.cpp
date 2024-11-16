#include "easyfind.hpp"

int main()
{
   std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    std::deque<int> d;
    d.push_back(6);
    d.push_back(7);
    d.push_back(8);
    d.push_back(9);
    d.push_back(10);

    std::list<int> l;
    l.push_back(11);
    l.push_back(12);
    l.push_back(13);
    l.push_back(14);
    l.push_back(15);
    try
    {
        std::cout << "Looking for 4" << std::endl;
        std::cout << "v e c t o r" << std::endl;
        easyfind(v, 4);
        std::cout << "d e q u e" << std::endl;
        easyfind(d, 4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "Looking for 7" << std::endl;
        std::cout << "d e q u e" << std::endl;
        easyfind(d, 7);
        std::cout << "l i s t" << std::endl;
        easyfind(l, 7);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "Looking for 15" << std::endl;
        easyfind(l, 15);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}