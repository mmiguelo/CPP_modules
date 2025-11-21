#pragma once

#include <iostream>
#include <string>


class ICharacter;

#define R		"\033[0;31m" //RED
#define G		"\033[0;32m" //GREEN
#define Y		"\033[0;33m" //YELLOW
#define B		"\033[0;34m" //BLUE
#define RST		"\033[0m"   //RESET

// abstract class since there is a purevirtal function
class AMateria
{
    protected:
        std::string type;
	
    public:
        AMateria();
        AMateria(const AMateria &other);
        AMateria(std::string const &type);
        virtual ~AMateria();
        AMateria &operator=(const AMateria &other);

        std::string const &getType() const; //Returns the materia type
	    //pure virtual function makes this class abstract
        //Therefore AMateria cannot be instantiated and acts like an interface / base class.
        //Clone is like a factory — it must return a newly allocated object
        virtual AMateria* clone() const = 0;
	    virtual void use(ICharacter &target);
};
