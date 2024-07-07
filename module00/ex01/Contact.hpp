#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>


class   Contact
{
    private:

        std::string number;
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string secret;
        bool    active;

    public:

        Contact();
        bool    getBool();
        bool    activate();
        void    setLastName(std::string &str);
        void    setNumber(std::string &str);
        void    setNickName(std::string &str);
        void    setSecret(std::string &str);
        void    setFirstName(std::string &str);

        const   std::string& getFirstName() const;
        const   std::string& getLastName() const;
        const   std::string& getNumber() const;
        const   std::string& getNickName() const;
        const   std::string& getSecret() const;
}

#endif 