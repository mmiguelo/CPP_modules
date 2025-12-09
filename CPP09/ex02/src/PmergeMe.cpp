#include "../PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << G << "PmergeMe: default constructor called" << RST << std::endl;
}

PmergeMe::~PmergeMe()
{
	std::cout << R << "PmergeMe: destructor called" << RST << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
    std::cout << G << "PmergeMe: Copy constructor called." << RST << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        // copy attributes here
    }
    std::cout << G << "Copy assignment operator called" << RST << std::endl;
    return *this;
}
