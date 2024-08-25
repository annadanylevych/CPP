#include "MateriaSource.hpp"

MateriaSource::MateriaSource() 
{
    for (int i = 0; i < 4; i++)
        this->slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& another) 
{
    for (int i = 0; i < 4; i++)
    {
        if (this->slots[i])
            delete this->slots[i];
        if (another.slots[i])
            this->slots[i] = another.slots[i]->clone();
        else
            this->slots[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource& another)
{
    if (this != &another)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->slots[i])
                delete this->slots[i];
            if (another.slots[i])
                this->slots[i] = another.slots[i]->clone();
            else
                this->slots[i] = NULL;
        }
    }
    return(*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->slots[i])
            delete this->slots[i];
    }
}

void    MateriaSource::learnMateria(AMateria* m)
{
    int i = 0;
    do 
    {
        if (!slots[i])
        {
            slots[i] = m;
            break;
        }
        i++;
    } while (i < 4);
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i = 0;
    do
    {
        if (type == slots[i]->getType())
            return (slots[i]->clone());
        i++;
    } while (i < 4);
    return (0);
}