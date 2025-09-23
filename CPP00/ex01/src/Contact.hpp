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
	void		setLastName(std::string str);
	std::string	getLastName();
	void		setNickname(std::string str);
	std::string	getNickname();
	void		setPhoneNumber(std::string str);
	std::string	getPhoneNumber();
	void		setDarkSecret(std::string str);
	std::string	getDarkSecret();
};
