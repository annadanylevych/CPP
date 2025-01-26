#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cerr << "Error: no parameters given" << std::endl;
        return (1);
    }
    try
    {
        std::list<int> myList = convert<std::list<int> >(argc, argv);
        std::cout << "LIST Before: ";
        printArr(myList);

        clock_t start_list = clock(); 
        std::list<int> sortedList = sortList(myList);
        clock_t end_list = clock(); 

        std::cout << "LIST After: ";
        printArr(sortedList);
        double time_list = static_cast<double>(end_list - start_list) / CLOCKS_PER_SEC;
        std::cout << "Time to process a range of " << myList.size() << " elements with std::list: " << time_list * 1e6 << " us" << std::endl;

       
        std::deque<int> myDeque = convert<std::deque<int> >(argc, argv);
        std::cout << "DEQUE Before: ";
        printArr(myDeque);

        clock_t start_deque = clock(); 
        std::deque<int> sortedDeque = mergeInsertSortDeque(myDeque);
        clock_t end_deque = clock(); 

        std::cout << "DEQUE After: ";
        printArr(sortedDeque);
        double time_deque = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC;
        std::cout << "Time to process a range of " << myDeque.size() << " elements with std::deque: " << time_deque * 1e6 << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
