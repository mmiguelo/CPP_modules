#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <sstream>
#include <algorithm>
#include <utility>
#include <cstddef>

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
		void insertAndValidate(int ac, char **av);
		void populateVector();
		void populateDeque();
		void error();
		std::vector<int>& getVector() { return _vector; }
		std::deque<int>& getDeque() { return _deque; }
    	const std::vector<int>& getVector() const { return _vector; }
    	const std::deque<int>& getDeque() const { return _deque; }
		const std::vector<int>& getBefore() const { return _before; }

	private:
		std::vector<int> _before;
		std::deque<int> _deque;
		std::vector<int> _vector;
};

void normalize(int &a, int &b);

#include "PmergeMe.tpp"

#endif