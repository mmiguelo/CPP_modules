#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other) {
    if (this != &other)
        *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        _before = other._before;
        _deque = other._deque;
        _vector = other._vector;
    }
    return *this;
}

void PmergeMe::error()
{
    std::cerr << "Error.\nInvalid Argument." << std::endl;
}

void    PmergeMe::insertAndValidate(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        std::istringstream iss(av[i]);
        std::string token;
        while (iss >> token)
        {
            if (token.empty())
                return(error());
            for (unsigned long j = 0; j < token.size(); j++)
            {
                if (!isdigit(token[j]))
                    return (error());
            }
            if (token.size() > 10)
                return (error());
            int num;
            std::stringstream ss(token);
            ss >> num;

            if (ss.fail() || num < 0)
                return(error());
            for (size_t i = 0; i < _vector.size(); i++)
            {
                if (_vector[i] == num)
                    return error();
            }
            _before.push_back(num);
        }
    }
}