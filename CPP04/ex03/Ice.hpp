#pragma once

#include "AMateria.hpp"
#include <iostream>
#include <string>

#define R		"\033[0;31m" //RED
#define G		"\033[0;32m" //GREEN
#define Y		"\033[0;33m" //YELLOW
#define B		"\033[0;34m" //BLUE
#define RST		"\033[0m"   //RESET

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