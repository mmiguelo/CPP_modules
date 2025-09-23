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
	std::string line;
	_i = _i % 8;

	while (_contact[_i].getFirstName().empty())
	{
		std::cout << "First Name: " << std::endl;
		std::getline(std::cin, line);
		_contact[_i].setFirstName(line);
	}
	while (_contact[_i].getLastName().empty())
	{
		std::cout << "Last Name: " << std::endl;
		std::getline(std::cin, line);
		_contact[_i].setLastName(line);
	}
	while (_contact[_i].getNickname().empty())
	{
		std::cout << "Nickname: " << std::endl;
		std::getline(std::cin, line);
		_contact[_i].setNickname(line);	
	}
	while (_contact[_i].getPhoneNumber().empty())
	{
		std::cout << "Phone number: " << std::endl;
		std::getline(std::cin, line);
		_contact[_i].setPhoneNumber(line);	
	}
	while (_contact[_i].getDarkSecret().empty())
	{
		std::cout << "Darkest Secret: " << std::endl;
		std::getline(std::cin, line);
		_contact[_i].setDarkSecret(line);	
	}
	_i++;
}

void	Phonebook::search()
{

}

void	Phonebook::exit()
{}