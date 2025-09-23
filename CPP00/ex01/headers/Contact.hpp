#ifndef CONTACT
# define CONTACT

#pragma once
#include <string>
#include <iostream>
#include <cstdio>
#include <cctype>

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
	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickname();
	std::string	getPhoneNumber();
	std::string	getDarkSecret();
	void		setFirstName(std::string str);
	void		setLastName(std::string str);
	void		setNickname(std::string str);
	void		setPhoneNumber(std::string str);
	void		setDarkSecret(std::string str);
	void		print_contact();
};

#endif