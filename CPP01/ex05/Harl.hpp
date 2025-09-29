#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#define RST "\033[0m"      // reset color
#define R "\033[1;31m"   // bold red
#define G   "\033[1;32m"   // bold green

class Harl
{
	private:
		void debug();
		void info();
		void warning();
		void error();
	public:
		void complain(std::string level);
};
