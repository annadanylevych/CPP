#pragma once

#include "Contact.hpp"

# include <iostream>
# include <iomanip>
# include <string>

class   PhoneBook
{
    public:
        PhoneBook();
        void    searchContact();
        void    addContact();
        void    printi(int i);
        
    private:
        Contact smbd[8];
};

