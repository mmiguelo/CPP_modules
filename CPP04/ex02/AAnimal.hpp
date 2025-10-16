#pragma once
#include <iostream>
#include <string>

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
        virtual void makeSound() const = 0;
};
