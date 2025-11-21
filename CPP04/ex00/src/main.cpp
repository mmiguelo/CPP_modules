#include "../Animal.hpp"
#include "../Dog.hpp"
#include "../Cat.hpp"
#include "../WrongCat.hpp"
#include "../WrongAnimal.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog(); //Using a base class pointer ensures proper polymorphic behavior.
    const Animal* i = new Cat();
	const WrongAnimal* l = new WrongAnimal();
	const WrongAnimal* k = new WrongCat(); // Will call WrongAnimal::makeSound(), NOT WrongCat

	{
		std::cout << j->getType() << " " << std::endl;
		j->makeSound();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		std::cout << meta->getType() << " " << std::endl;
		meta->makeSound();
		std::cout << l->getType() << " " << std::endl;
		l->makeSound();
		std::cout << k->getType() << " " << std::endl;
		k->makeSound(); //makeSound() is not virtual, so it calls the base class method
	}

	{
		delete meta;
		delete j;
		delete i;
		delete l;
		delete k;
	}

	return 0;
}