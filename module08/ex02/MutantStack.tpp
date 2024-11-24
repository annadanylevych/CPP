#include "MutantStack.hpp"

template <typename T> 
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T> 
MutantStack<T>::MutantStack(MutantStack<T>& another) : std::stack<T>(another) {}

template <typename T> 
MutantStack<T>::~MutantStack() {}

template <typename T> 
MutantStack<T>& MutantStack<T>::operator=(MutantStack& another)
{
    if (this != &another)
        std::stack<T>::operator=(another);
    return (*this);
}

template <typename T> 
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}

template <typename T> 
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (this->c.end());
}

template <typename T> 
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return (this->c.begin());
}

template <typename T> 
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return (this->c.end());
}
