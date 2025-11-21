#pragma once

#include <string>

class AMateria;

class ICharacter
{
    public:
        //Why destructors must be virtual in interfaces?
        //Because deleting derived objects through base pointers must call the correct destructor.
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
	    virtual void equip(AMateria* m) = 0;
        virtual void unequip(int index) = 0;
        virtual void use(int index, ICharacter& target) = 0;
};