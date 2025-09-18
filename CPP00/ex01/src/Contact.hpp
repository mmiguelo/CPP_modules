#pragma once
#include "Phonebook.hpp"

class Contact 
{
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
public:
	Contact();
	~Contact();
	void		setFirstName(std::string str);
	std::string	getFirstName();
};