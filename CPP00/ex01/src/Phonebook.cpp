#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	_i = 0;
	std::cout << "Class Phonebook was created" << std::endl;
}

Phonebook::~Phonebook()
{
	std::cout << "Class Phonebook was destroyed" << std::endl;
}

void Phonebook::add()
{
	if (_i > 7)
		_i = 0;
	std::cout << "First Name: " << std::endl;
	_contact[_i].setFirstName(std::getline(std::cin, line));
}

void	Phonebook::search()
{
}

void	Phonebook::exit()
{}