#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "Colours.hpp"
#include <iostream>

PhoneBook::PhoneBook() : size(0) {}

void    PhoneBook::searchContact()
{
    if (this->size == 0)
        std::cout << "There are no contacts yet" << std::endl;
}

void    PhoneBook::addContact()
{
    std::string info;

    std::cout << MAGENTA "Enter the name: " RESET;
    std::cin >> info;

}