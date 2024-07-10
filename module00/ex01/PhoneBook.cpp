#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "Colours.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{}

void    PhoneBook::searchContact()
{
    if (this->smbd[0].getBool() == false)
        std::cout << YELLOW "There are no contacts yet" RESET << std::endl;
}

void    PhoneBook::addContact()
{
    std::string info;

    std::cout << MAGENTA "Enter the name: " RESET;
    std::cin >> info;

}