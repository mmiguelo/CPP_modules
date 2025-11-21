#pragma once
#include <iostream>
#include <string>


//What is polymorphism?

//Polymorphism allows a base class pointer or reference to call
//methods that are overridden by derived classes.
//This means the same function call (makeSound()) results in different
//behavior depending on the actual object type (Dog, Cat).
class Animal
{
    protected:
        std::string type;

    public:
        Animal();
        Animal(const Animal &other);
        virtual ~Animal();
        Animal &operator=(const Animal &other);

        std::string getType() const;
        virtual void makeSound() const; // this is a virtual function to allow different sounds depending on the animal type
};
