#pragma once

#include <iostream>
#include <string>
#include <map>
#include <cstdlib>

#define RST "\033[0m"      // reset color
#define R "\033[1;31m"   // bold red
#define G   "\033[1;32m"   // bold green

enum levelType
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	INVALID
};

class Harl
{
	private:
		std::map<std::string, void (Harl::*)()> type;
		void debug();
		void info();
		void warning();
		void error();
	public:
		Harl();
		~Harl();
		void complain(std::string level);
		void filter(std::string level);
};