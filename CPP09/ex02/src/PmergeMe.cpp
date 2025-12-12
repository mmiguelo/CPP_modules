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

void    PmergeMe::readInput(int ac, char **av)
{
    for (int i = 1; i < ac, i++)
    {
        std::istringstream iss(av[i]);
        std::string token;
        while (iss >> token)
        {
            bool isValid = true;
            if (token.empty)
                isValid = false;
            for (int j = 0; j < token.size(); j++)
            {
                if (!isdigit(token[j]))
                {
                    isValid = false;
                    break;
                }
            }
            if (isValid == false)
            {
                std::cerr << "Error.\nInvalid argument." << std::endl;
                return ;
            }
            try
            {
                int num;
                std::stringstream ss(token);
                ss >> num;
                if (ss.fail)
                {
                    std::cerr << "Error.\nInvalid argument." << std::endl;
                    return ;
                }
            }
            _vector.push_back(token);
            _deque.push_back(token);
            catch
            {
                
            }
        }
    }
}