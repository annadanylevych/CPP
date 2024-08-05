# pragma once

# include <string>

class Zombie
{
private:
    std::string name;
public:
    Zombie();
    ~Zombie();
    void    announce(void);
    void    setname(std::string str);
    std::string    getname();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
Zombie* zombieHorde( int N, std::string name );