#include "PmergeMe.hpp"

void PmergeMe::populateVector() {
	_vector.clear();
	for (size_t i = 0; i < _before.size(); i++)
		_vector.push_back(_before[i]);
}

void PmergeMe::populateDeque() {
	_deque.clear();
	for (size_t i = 0; i < _before.size(); i++)
		_deque.push_back(_before[i]);
}

void normalize(int &a, int &b) {
    if (a > b)
        std::swap(a, b);
}