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
    	const std::vector<int>& getVector() const { return _vector; }
    	const std::deque<int>& getDeque() const { return _deque; }
		const std::vector<int>& getBefore() const { return _before; }

	private:
		std::vector<int> _before;
		std::deque<int> _deque;
		std::vector<int> _vector;
};

void normalize(int &a, int &b);

template <typename Container> bool isSorted(const Container& input) {
	for (size_t i = 1; i < input.size(); i++) {
		if (input[i - 1] > input[i]) {
			return false;
		}
	}
	return true;
}

template <typename Container> std::vector< std::pair<int, int> > createPairs(const Container& input, int& straggler, bool& hasStraggler)
{
    std::vector< std::pair<int, int> > pairs;

    size_t i = 0;
    for (; i + 1 < input.size(); i += 2)
    {
        int a = input[i];
        int b = input[i + 1];

        normalize(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    if (i < input.size())
    {
        straggler = input[i];
        hasStraggler = true;
    }
    else
        hasStraggler = false;

    return pairs;
}

#include "PmergeMe.tpp"

#endif