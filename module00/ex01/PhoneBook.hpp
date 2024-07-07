#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

# include <iostream>
# include <iomanip>
# include <string>

class   PhoneBook
{
    public:

        void    searchContact();
        void    addContact();
        void    isActive(Contact x);
        
    private:
        Contact smbd[8];
}

#endif

