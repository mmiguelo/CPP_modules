#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <string>

#define R		"\033[0;31m" //RED
#define G		"\033[0;32m" //GREEN
#define Y		"\033[0;33m" //YELLOW
#define BL		"\033[0;34m" //BLUE
#define RST		"\033[0m"   //RESET

class Base 
{
	public:
		virtual ~Base();  // Destructor
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
