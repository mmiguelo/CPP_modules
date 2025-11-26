#include "../inc/span.hpp"

span::span() : _N(0)
{
	std::cout << G << "span: default constructor called" << RST << std::endl;
}

span::span(unsigned int nbr) : _N(nbr)
{
    std::cout << G << "Span was created with " << nbr << " elements" << RST << std::endl;
}

span::~span()
{
	std::cout << R << "span: destructor called" << RST << std::endl;
}

span::span(const span &other) : _N(other._N)
{
    std::cout << G << "span: Copy constructor called." << RST << std::endl;
    for (size_t i = 0; i < other.storage.size(); i++)
        this->storage[i] = other.storage[i];
}

span& span::operator=(const span &other) {
    if (this != &other) {
        this->_N = other._N;
        for (size_t i = 0; i < other.storage.size(); i++)
            this->storage[i] = other.storage[i];
    }
    std::cout << G << "Copy assignment operator called" << RST << std::endl;
    return *this;
}

void span::addNumber(unsigned int number)
{
    if (storage.size() >= _N)
        throw fullException();
    storage.push_back(number);
    std::cout << Y << "Number " << number << " added to span" << RST << std::endl;
}

unsigned int span::shortestSpan()
{
    if(storage.size() < 2)
        throw minimumException();
    
    std::vector<int> copy = storage;
    std::sort(copy.begin(), copy.end());

    int shortSpan = abs(copy[0] - copy[1]);

    for (size_t i = 0; i < storage.size(); i++)
    {
        if (i + 1 < storage.size())
        {
            if (shortSpan > abs(copy[i] - copy[i + 1]))
                shortSpan = abs(copy[i] - copy[i + 1]);
        }   
    }
    return (shortSpan);
}

unsigned int span::longestSpan()
{
    if(storage.size() < 2)
        throw minimumException();
    
    std::vector<int> copy = storage;
    std::sort(copy.begin(), copy.end());

    return(abs(copy.front() - copy.back()));
}

void span::addRandomNumbers(unsigned int quantity)
{
    if (storage.size() + quantity > _N)
        throw fullException();
    storage.reserve(storage.size() + quantity);

    for (unsigned int i = 0; i < quantity; i++)
        storage.push_back(rand());
}

unsigned int span::amount()
{
    return storage.size();
}