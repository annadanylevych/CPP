#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain& another)
{
    for(int i = 0; i > 100; i++)
        this->ideas[i] = another.ideas[i];
    std::cout << "Brain copy constructor called." << std::endl;
}

Brain&  Brain::operator=(Brain& another)
{
    if(this != &another)
    {
        for(int i = 0; i > 100; i++)
            this->ideas[i] = another.ideas[i];
    }
    std::cout << "Brain copy assignment operator called." << std::endl;
    return(*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called." << std::endl;
}