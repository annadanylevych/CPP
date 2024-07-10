#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "Colours.hpp"
#include <iostream>
#include <cctype> 
#include <cstdlib> 

PhoneBook::PhoneBook()
{}

bool     checkNum(std::string& str)
{
    for (std::string::const_iterator i = str.begin(); i != str.end(); ++i)
    {
        if (!std::isdigit(*i))
            return (false);
    }
    return (true);
}

bool    whiteSpace(std::string& str)
{
    
}

void    PhoneBook::searchContact()
{
    if (this->smbd[0].getBool() == false)
        std::cout << YELLOW "There are no contacts yet" RESET << std::endl;
}

void    PhoneBook::addContact()
{
    std::string info;
    int i;

    for(i = 0; i < 9; i++)
    {
        if (smbd[i].getBool() == false)
            break;
    }
    std::cout << MAGENTA "Enter first name: " RESET;
    getline(std::cin, info);
    if(std::cin.eof())
        exit(1);
    if(std::isspace())
    smbd[i].setFirstName(info);
    std::cout << MAGENTA "Enter last name: " RESET;
    getline(std::cin, info);
    if(std::cin.eof())
        exit(1);
    smbd[i].setLastName(info);
    std::cout << MAGENTA "Enter the number: " RESET;
    getline(std::cin, info);
    if(std::cin.eof())
        exit(1);
    while (checkNum(info) == false || info.length() > 9)
    {
        std::cout << RED "Number not valid. Try again: " RESET;
        getline(std::cin, info);
        if(std::cin.eof())
            exit(1);
    }
    smbd[i].setNumber(info);
    std::cout << MAGENTA "Enter nickname: " RESET;
    getline(std::cin, info);
    if(std::cin.eof())
        exit(1);
    smbd[i].setNickName(info);
    std::cout << MAGENTA "Enter the darskest secret: " RESET;
    getline(std::cin, info);
    if(std::cin.eof())
        exit(1);
    smbd[i].setSecret(info);
    std::cout << GREEN BOLD "CONGRATULATIONS! CONTACT ADDED SUCCESSFULLY!" RESET << std::endl;

}