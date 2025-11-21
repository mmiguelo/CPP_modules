#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>
#include <string>

#define R		"\033[0;31m" //RED
#define G		"\033[0;32m" //GREEN
#define Y		"\033[0;33m" //YELLOW
#define B		"\033[0;34m" //BLUE
#define RST		"\033[0m"   //RESET

class Intern 
{
	public:
    	Intern();                 // Default constructor
		Intern(const Intern &other); // Copy constructor
		~Intern();                // Destructor
		Intern &operator=(const Intern &other); // Copy assignment

		AForm* makeForm(std::string formName, std::string formTarget);

		class WrongForm: public std::exception 
		{
			public:
				virtual const char* what() const throw()
				{
					return "Error: Form name does not exist";
				}
		};

		class EmptyTarget: public std::exception
		{
			public:
    			virtual const char* what() const throw()
				{
        			return "Error: form target cannot be empty";
    			}
		};
};

#endif
