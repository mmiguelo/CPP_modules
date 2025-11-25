#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <iterator>

# define RST "\033[0m"
# define R "\033[31;1m"
# define G "\033[32;1m"
# define Y "\033[33;1m"
# define B "\033[0;36m"
# define MAG "\033[35;1m"

class notFoundException : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return "Error: No occurance was found\n";
        }
};

template <typename T> void easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end())
        std::cout << G << "Found " << value << " at position " << std::distance(container.begin(), it) << RST << std::endl;
    else
        throw notFoundException();
}

#endif