#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "Colours.hpp"
#include <iostream>
#include <cctype> 
#include <cstdlib> 
#include <iomanip>

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

void    Phonebook::printi(int i)
{
    int y = 0;
    if(smbd[i].length() > 10)
        std::cout << CYAN << smbd[i].getFirstName().substr(0, 9) << ".|" << RESET;
    else
    {
        std::cout << CYAN << smbd[i].getFirstName() << RESET;
        while()

}

int    whiteSpace(std::string& str)
{
    int i = 0;
    while(str[i])
    {
        if(!isspace(str[i]))
            return(0);
        i++;
    }
    return(1);
}

void    PhoneBook::searchContact()
{
    int i = 0;

    if (smbd[0].getBool() == false)
        std::cout << YELLOW "There are no contacts yet" RESET << std::endl;
    else
    {
        while(smbd[i++].getBool() == true)
        {
            std::cout << GREEN BOLD "I N D E X |FIRST name|LAST name |NICK name " RESET << std::endl;
            std::cout << CYAN << i << "         |" RESET;
            std::cout << CYAN << smbd[0].getLastName().substr(0, 9) << ".|" << RESET;
            std::cout << CYAN << smbd[0].getNickName().substr(0, 9) << ".|" << RESET;
            std::cout << CYAN << smbd[0].getSecret().substr(0, 9) << ".|" << RESET << std::endl;
        }
    }
}

void    PhoneBook::addContact()
{
    std::string info;
    
    int i;

    std::cout << info[0] << std::endl;

    for(i = 0; i < 9; i++)
    {
        if (smbd[i].getBool() == false)
            break;
    }
    std::cout << MAGENTA "Enter first name: " RESET;
    getline(std::cin, info);
    if(std::cin.eof())
        exit(1);
    while (whiteSpace(info))
    {
        std::cout << RED "Name not valid. Try again: " RESET;
        getline(std::cin, info);
        if(std::cin.eof())
            exit(1);
    }
    smbd[i].setFirstName(info);
    std::cout << MAGENTA "Enter last name: " RESET;
    getline(std::cin, info);
    if(std::cin.eof())
        exit(1);
     while (whiteSpace(info))
    {
        std::cout << RED "Last name not valid. Try again: " RESET;
        getline(std::cin, info);
        if(std::cin.eof())
            exit(1);
    }
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
     while (whiteSpace(info))
    {
        std::cout << RED "Nickname not valid. Try again: " RESET;
        getline(std::cin, info);
        if(std::cin.eof())
            exit(1);
    }
    smbd[i].setNickName(info);
    std::cout << MAGENTA "Enter the darskest secret: " RESET;
    getline(std::cin, info);
    if(std::cin.eof())
        exit(1);
     while (whiteSpace(info))
    {
        std::cout << RED "Secret not dark enough. Try again: " RESET;
        getline(std::cin, info);
        if(std::cin.eof())
            exit(1);
    }
    smbd[i].setSecret(info);
    smbd[i].activate();
    std::cout << GREEN BOLD "CONGRATULATIONS! CONTACT ADDED SUCCESSFULLY!" RESET << std::endl;
}