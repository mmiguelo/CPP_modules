#pragma once

#include "Character.hpp"
#include <iostream>
#include <string>

#define R		"\033[0;31m" //RED
#define G		"\033[0;32m" //GREEN
#define Y		"\033[0;33m" //YELLOW
#define B		"\033[0;34m" //BLUE
#define RST		"\033[0m"   //RESET

class AMateria
{
    protected:
        std::string type;
	
    public:
        AMateria();
        AMateria(const AMateria &other);
        AMateria(std::string const & type);
        virtual ~AMateria();
        AMateria &operator=(const AMateria &other);

        std::string const & getType() const; //Returns the materia type
	    virtual AMateria* clone() const = 0;
	    virtual void use(ICharacter& target);
};
