#include "PmergeMe.hpp"

bool isNum(std::string str)
{
    for (unsigned long i = 0; i < str.length(); ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

std::list<int> sortList(std::list<int> unsorted)
{
    std::list<int>  sortedList;
    std::list<std::pair<int, int > > pairs;

    if (isSorted(unsorted))
        return (unsorted);
    std::list<int>::iterator it = unsorted.begin();
	while (it != unsorted.end())
	{
		std::list<int>::iterator next = it;
		++next;

		if (next != unsorted.end())
		{
			pairs.push_back(std::make_pair(*it, *next));
			it = ++next; 
		}
		else
		{
			pairs.push_back(std::make_pair(-1, *it));
			++it;
		}
	}

    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if ((*it).first != -1 && (*it).first > (*it).second)
			std::swap((*it).first, (*it).second);
	}
    
    sortPairsList(pairs);
    
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        if ((*it).first > 0)
            sortedList.push_back((*it).first);
    }

    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
        binarySearchInsertionList(sortedList, sortedList.begin(), sortedList.end(), (*it).second);
    return (sortedList);
}


void    sortPairsList(std::list<std::pair<int, int > >& pairs)
{
    if (pairs.begin() == pairs.end())
    return ;

    std::list<std::pair<int, int > >::iterator it = pairs.begin();
    ++it;

    while (it != pairs.end())
    {
		std::list<std::pair<int, int> >::iterator current = it;
		std::list<std::pair<int, int> >::iterator prev = current;
		--prev;

		while (prev != pairs.begin() && (*current).first > 0 && (*current).first < (*prev).first)
		{
			std::swap(*current, *prev);
			current = prev;
			--prev;
		}

		if (prev == pairs.begin() && (*current).first > 0 && (*current).first < (*prev).first)
			std::swap(*current, *prev);
        ++it;
    }
}


void binarySearchInsertionList(std::list<int>& cont, std::list<int>::iterator left, std::list<int>::iterator right, int target)
{
    while (left != right)
    {
        std::list<int>::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);

        if (*mid < target)
            left = ++mid;
        else
            right = mid;
    }
    
    cont.insert(left, target);
}


std::deque<int>	mergeInsertSortDeque(std::deque<int> unsortedDeque)
{
	std::deque<int>					sortedDeque;
	std::deque<std::pair<int, int> >	pairs;

	if (isSorted(unsortedDeque))
	{
		sortedDeque = unsortedDeque;
		return (sortedDeque);
	}
	for (std::deque<int>::iterator it = unsortedDeque.begin(); it != unsortedDeque.end(); it++)
	{
		if (it < unsortedDeque.end() - 1)
		{
			pairs.push_back(std::make_pair(*it, *(it + 1)));
			it++;
		}
		else
			pairs.push_back(std::make_pair(-1, *it));
	}

	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if ((*it).first > (*it).second)
			std::swap((*it).first, (*it).second);
	}
	insertionSortPairs(pairs);
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if ((*it).first > 0)
			sortedDeque.push_back((*it).first);
	}
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if ((*it).first > 0)
			binarySearchInsertion(sortedDeque, std::distance(pairs.begin(), it) + 1, sortedDeque.size(), (*it).second);
		else
			binarySearchInsertion(sortedDeque, 0, sortedDeque.size(), (*it).second);
	}
	return (sortedDeque);
}

void binarySearchInsertion(std::deque<int> &cont, int left, int right, int target)
{
    int	mid;

	if (left == right)
	{
		cont.push_back(target);
		return;
	}

    while (left <= right)
    {
        mid = left + (right - left) / 2;
		if (cont[mid] < target)
			left = mid + 1;
   		else
      		right = mid - 1;
  	}
  	if (left < static_cast<int>(cont.size()))
		cont.insert(cont.begin() + left, target);
 	else
		cont.push_back(target);
}

void	insertionSortPairs(std::deque<std::pair<int, int> > & pairs)
{
	if (pairs.begin() == pairs.end())
		return ;
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin() + 1; it != pairs.end(); it++)
	{
		std::deque<std::pair<int, int> >::iterator it_next = it;
		for (std::deque<std::pair<int, int> >::iterator it_prev = it_next - 1; it_prev >= pairs.begin() && (*it_next).first > 0; it_prev--, it_next--)
		{
			if ((*it_next).first < (*it_prev).first)
				std::swap((*it_next), (*it_prev));
		}
	}
}
