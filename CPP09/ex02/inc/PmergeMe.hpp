#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>

#define R		"\033[0;31m" //RED
#define G		"\033[0;32m" //GREEN
#define Y		"\033[0;33m" //YELLOW
#define B		"\033[0;34m" //BLUE
#define RST		"\033[0m"   //RESET

class PmergeMe 
{
	public:
    	PmergeMe();                 // Default constructor
		PmergeMe(const PmergeMe &other); // Copy constructor
		~PmergeMe();                // Destructor
		PmergeMe &operator=(const PmergeMe &other); // Copy assignment
};

#endif
