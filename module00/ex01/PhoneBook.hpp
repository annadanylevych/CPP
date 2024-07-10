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
        
    private:
        Contact smbd[8];
};

