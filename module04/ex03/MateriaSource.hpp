#pragma once

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <string>

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* slots[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& another);
        MateriaSource& operator=(MateriaSource& another);
        ~MateriaSource();
        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);
};