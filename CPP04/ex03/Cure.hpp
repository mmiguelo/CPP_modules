#pragma once

#include "AMateria.hpp"
#include <string>
#include <iostream>

#define R		"\033[0;31m" //RED
#define G		"\033[0;32m" //GREEN
#define Y		"\033[0;33m" //YELLOW
#define B		"\033[0;34m" //BLUE
#define RST		"\033[0m"   //RESET

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure &other);
        Cure &operator=(const Cure &other);
        virtual ~Cure();

        Cure* clone() const;
        void use(ICharacter& target);
};
