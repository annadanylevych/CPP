#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact() : active(false){}

bool    Contact::getBool()
{
    return(this->active);
}

bool    Contact::activate()
{
    return(this->active = true);
}

void    Contact::setFirstName(std::string &str)
{
    this->firstName = str;
}

void    Contact::setLastName(std::string &str)
{
    this->lastName = str;
}

void    Contact::setNumber(std::string &str)
{
    this->number = str;
}

void    Contact::setNickName(std::string &str)
{
    this->nickName = str;
}

void    Contact::setSecret(std::string &str)
{
    this->secret = str;
}

const   std::string& Contact::getFirstName() const
{
    return(this->firstName);
}

const   std::string& Contact::getLastName() const
{
    return(this->lastName);
}

const   std::string& Contact::getNumber() const
{
    return(this->number);
}

const   std::string& Contact::getNickName() const
{
    return(this->nickName);
}

const   std::string& Contact::getSecret() const
{
    return(this->secret);
}

