#pragma once;
#include <iostream>
#include "Contact.hpp"

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
	void	exit();
};