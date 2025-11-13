#include "../Character.hpp"
#include "../Cure.hpp"
#include "../Ice.hpp"
#include "../MateriaSource.hpp"
#include <iostream>

void print(const std::string &title)
{
	std::cout << B << "\n==== " << title << " ====\n" << RST;
}

void subject()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return ;
}
void my_test()
{
	std::cout << B << "\n	--Starting My Tests--\n" << RST << std::endl;

	std::cout << "Creating Materia Source" << std::endl;
	IMateriaSource* src = new MateriaSource();

	print("Learning Materias");
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());

	print("Creating Characters");
	ICharacter* Tarnished = new Character("Tarnished");
	ICharacter* Cinder = new Character("Cinder");

	print("Creating and Equipping Materias");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	Tarnished->equip(tmp);
	Tarnished->equip(src->createMateria("cure"));
	Tarnished->equip(src->createMateria("ice"));
	Tarnished->equip(src->createMateria("cure"));
	AMateria *ice = src->createMateria("ice");
	// This will result in an error and a leak since inv is full.
	// However because of the subject, I can not handle this leak.
	Tarnished->equip(ice);
	delete ice;

	print("Using Materias");
	Tarnished->use(0, *Cinder);
	Tarnished->use(1, *Cinder);
	Tarnished->use(4, *Cinder);

	print("Unequipping a Materia");
	Tarnished->unequip(0);

	print("Using After Unequip");
	Tarnished->use(0, *Cinder);

	print("Cinder Equips and Uses");
	AMateria* ice2 = src->createMateria("ice");
	Cinder->equip(ice2);
	Cinder->use(0, *Tarnished);

	print("Invalid Materia Creation");
	AMateria* unknown = src->createMateria("fire");
	if (!unknown)
		std::cout << R << "Unknown materia could not be created" << RST << std::endl;

	print("Cleaning up");
	delete Cinder;
	delete Tarnished;
	delete src;
}

int main()
{
	std::cout << "----- Subject Main -----" << std::endl;
	std::cout << std::endl;
	subject();
	std::cout << std::endl;
	std::cout << std::endl;
	my_test();
	std::cout << std::endl;
	return 0;
}