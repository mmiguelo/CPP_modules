#include "../inc/PmergeMe.hpp"

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
    (void)other; 
    std::cout << G << "Copy assignment operator called" << RST << std::endl;
    return *this;
}

void PmergeMe::error()
{
    std::cerr << "Error.\nInvalid Argument." << std::endl;
}

void    PmergeMe::readInput(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        std::istringstream iss(av[i]);
        std::string token;
        while (iss >> token)
        {
            if (token.empty())
                return(error());
            for (int j = 0; j < token.size(); j++)
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
            _vector.push_back(num);
            _deque.push_back(num);
        }
    }
    std::cout << "Congratulations" << std::endl;
}