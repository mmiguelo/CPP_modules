#pragma once
#include <iostream>
#include <string>

/* Abstract Class:

What is an abstract class?

A class with at least one pure virtual function*/

class AAnimal
{
    protected:
        std::string type;

    public:
        AAnimal();
        AAnimal(const AAnimal &other);
        virtual ~AAnimal();
        AAnimal &operator=(const AAnimal &other);

        std::string getType() const;
        //const = 0 forces derived classes to implement this method
        /* Why Animal should not be instantiable?

        Because there is no generic Animal sound.
        It makes no sense to create “just an Animal”.
        Real animals are concrete types. */
        virtual void makeSound() const = 0;
};
