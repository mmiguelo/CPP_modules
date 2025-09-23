#ifndef PHONE_BOOK
# define PHONE_BOOK

#pragma once
#include <iostream>
#include "./Contact.hpp"
#include <cctype>
#include <string>
#include <iomanip>
#include <cstdio>

class Phonebook 
{
private:
	int	_i;
	Contact _contact[8];
public:
	Phonebook();
	~Phonebook();
	void	add();
	void	search();
	bool	check_digit(std::string str);
};

#endif