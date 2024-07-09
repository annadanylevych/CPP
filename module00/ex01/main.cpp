
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Colours.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    (void)argv;
    if (argc > 1)
    {
        std::cout << RED BOLD "ERROR: PLEASE TRY AGAIN WITHOUT PARAMETERS" RESET << std::endl;
        return (0);
    }
    PhoneBook   book;
    std::string choice;

    std::cout << BG_YELLOW GREEN BOLD "WELCOME TO MY AWESOME PHONEBOOK :)" RESET << std::endl;
    std::cout << GREEN "Would you like to: " RESET << std::endl;
    std::cout << BLUE "   -ADD" RESET YELLOW " new contact" RESET << std::endl;
    std::cout << MAGENTA "   -SEARCH" RESET YELLOW " for a contact" RESET << std::endl;
    std::cout << RED "   -EXIT :(" RESET << std::endl;
    std::cout << CYAN "PLEASE ENTER YOUR CHOICE (IN UPPER CASE): " RESET ;
    std::cin >> choice;
    if (choice == "ADD")
        book.addContact();
    //else if (choice == "SEARCH")
    //    book.searchContact();
//    else if (choice == "EXIT")

}