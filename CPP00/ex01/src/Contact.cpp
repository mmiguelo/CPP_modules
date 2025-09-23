#include "../headers/Contact.hpp"

Contact::Contact()
{
	std::cout << "Class Contact was created" << std::endl;
}

Contact::~Contact()
{
	std::cout << "Class Contact was destroyed" << std::endl;
}

void Contact::print_contact()
{
	std::cout << "First Name: " << getFirstName() << std::endl;
	std::cout << "Last Name: " << getLastName() << std::endl;
	std::cout << "Nickname: " << getNickname() << std::endl;
	std::cout << "Phone Number: " << getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << getDarkSecret() << std::endl;
}

void Contact::setFirstName(std::string str)
{
	_firstName = str;
}

std::string Contact::getFirstName()
{
	return _firstName;
}

void Contact::setLastName(std::string str)
{
	_lastName = str;
}

std::string Contact::getLastName()
{
	return _lastName;
}

void Contact::setNickname(std::string str)
{
	_nickname = str;
}

std::string Contact::getNickname()
{
	return _nickname;
}

void Contact::setPhoneNumber(std::string str)
{
	_phoneNumber = str;
}

std::string Contact::getPhoneNumber()
{
	return _phoneNumber;
}

void Contact::setDarkSecret(std::string str)
{
	_darkestSecret = str;
}

std::string Contact::getDarkSecret()
{
	return _darkestSecret;
}
