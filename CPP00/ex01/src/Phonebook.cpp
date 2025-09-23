#include "../headers/Phonebook.hpp"

Phonebook::Phonebook() : _i(0)
{
	std::cout << "Class Phonebook was created" << std::endl;
}

Phonebook::~Phonebook()
{
	std::cout << "Class Phonebook was destroyed" << std::endl;
}

bool	Phonebook::check_digit(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

std::string truncate(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void Phonebook::add()
{
	int position = Phonebook::_i % 8;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	std::cout << "Enter first name: " << std::endl;
	std::getline(std::cin, firstName);
	std::cout << "Enter last name: " << std::endl;
	std::getline(std::cin, lastName);
	std::cout << "Enter nickname: " << std::endl;
	std::getline(std::cin, nickname);
	std::cout << "Enter phone number: " << std::endl;
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter darkest secret: " << std::endl;
	std::getline(std::cin, darkestSecret);
	if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << "Error: All fields must be filled." << std::endl;
		return ;
	}
	if (!check_digit(phoneNumber))
	{
		std::cout << "Error: Phone number must contain only digits." << std::endl;
		return ;
	}
	Phonebook::_i++;
	Phonebook::_contact[position].setFirstName(firstName);
	Phonebook::_contact[position].setLastName(lastName);
	Phonebook::_contact[position].setNickname(nickname);
	Phonebook::_contact[position].setPhoneNumber(phoneNumber);
	Phonebook::_contact[position].setDarkSecret(darkestSecret);
}

void	Phonebook::search()
{
	if (_i > 0)
		std::cout << "     Index|First name|  Lastname|  Nickname|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (i < _i)
		{
			std::cout << std::setw(10) << i << "|"
					  << std::setw(10) << truncate(_contact[i].getFirstName()) << "|"
					  << std::setw(10) << truncate(_contact[i].getLastName()) << "|"
					  << std::setw(10) << truncate(_contact[i].getNickname()) << "|"
					  << std::endl;
		}
	}
	std::string index;
	std::cout << "Enter index to view details: " << std::endl;
	std::getline(std::cin, index);
	if (index.length() == 1 && index[0] >= '0' && index[0] <= '7')
	{
		int i = index[0] - '0';
		if (i < _i)
		{
			std::cout << "First Name: " << _contact[i].getFirstName() << std::endl;
			std::cout << "Last Name: " << _contact[i].getLastName() << std::endl;
			std::cout << "Nickname: " << _contact[i].getNickname() << std::endl;
			std::cout << "Phone Number: " << _contact[i].getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << _contact[i].getDarkSecret() << std::endl;
		}
	}
	else
		std::cout << "Invalid Index: Index must be a numeric value between 0 and 7" << std::endl;
}
