#pragma once

#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice &other);
        Ice &operator=(const Ice &other);
        virtual ~Ice();

        Ice* clone() const;
        void use(ICharacter& target);
};