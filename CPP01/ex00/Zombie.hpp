#ifndef ZOMBIE
#define ZOMBIE

#pragma once
#include <iostream>
#include <string>
#include <iomanip>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie(std::string name);
		~Zombie();
		void announce();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif