#pragma once

#include "Character.hpp"
#include <iostream>
#include <string>

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
