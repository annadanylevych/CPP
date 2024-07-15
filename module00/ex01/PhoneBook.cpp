#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "Colours.hpp"
#include <iostream>
#include <cctype> 
#include <cstdlib> 
#include <iomanip>

PhoneBook::PhoneBook():qtt(0)
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

void    PhoneBook::printi(int i)
{
    if (smbd[i].getFirstName().length() > 10)
        std::cout << CYAN << smbd[i].getFirstName().substr(0, 9) << ".|" << RESET;
    else
    {
        std::cout << CYAN << smbd[i].getFirstName() << RESET;
        for (int y = smbd[i].getFirstName().length(); y < 10; y++)
            std::cout << " ";
        std::cout << CYAN "|" RESET;
    }
    if (smbd[i].getLastName().length() > 10)
        std::cout << CYAN << smbd[i].getLastName().substr(0, 9) << ".|" << RESET;
    else
    {
        std::cout << CYAN << smbd[i].getLastName() << RESET;
        for (int y = smbd[i].getLastName().length(); y < 10; y++)
            std::cout << " ";
        std::cout << CYAN "|" RESET;
    }
    if (smbd[i].getNickName().length() > 10)
        std::cout << CYAN << smbd[i].getNickName().substr(0, 9) << ".|" << RESET;
    else
    {
        std::cout << CYAN << smbd[i].getNickName() << RESET;
        for (int y = smbd[i].getNickName().length(); y < 10; y++)
            std::cout << " ";
         std::cout << std::endl;
    }

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
    int numi;

    std::string num;

    if (smbd[0].getBool() == false)
        std::cout << YELLOW "There are no contacts yet" RESET << std::endl;
    else
    {
        std::cout << GREEN BOLD "I N D E X |FIRST name|LAST name |NICK name " RESET << std::endl;
        while(smbd[i].getBool() == true)
        {
            std::cout << CYAN << i + 1 << "         |" RESET;
            printi(i);
            i++;
        }
        std::cout << YELLOW BOLD "Please enter the index of the contact: " RESET << std::endl;
        getline(std::cin, num);
        if(std::cin.eof())
            exit(1);
        numi = std::atoi(num.c_str());
        while (numi > 8 || numi < 1 || smbd[numi - 1].getBool() == false)
        {
            std::cout << RED BOLD "Please enter the existing index: " RESET << std::endl;
            getline(std::cin, num);
            if(std::cin.eof())
                exit(1);
            numi = std::atoi(num.c_str());
        }
        std::cout << CYAN "First name: " << smbd[numi - 1].getFirstName() << RESET << std::endl;
        std::cout << CYAN "Last name: " << smbd[numi - 1].getLastName() << RESET << std::endl;
        std::cout << CYAN "Nick name: " << smbd[numi - 1].getNickName() << RESET << std::endl;
        std::cout << CYAN "Number: " << smbd[numi - 1].getNumber() << RESET << std::endl;
        std::cout << CYAN "Darkest secret: " << smbd[numi - 1].getSecret() << RESET << std::endl;
    }   
}

void    PhoneBook::addContact()
{
    std::string info;
    
    int i = qtt % 8;

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
    qtt++;
}

