#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

#define R		"\033[0;31m" //RED
#define G		"\033[0;32m" //GREEN
#define Y		"\033[0;33m" //YELLOW
#define B		"\033[0;34m" //BLUE
#define RST		"\033[0m"   //RESET

class span 
{
	private:
		unsigned int _N;
		std::vector<int> storage;

	public:
    	span();
		span(unsigned int nbr);
		span(const span &other);
		~span();
		span &operator=(const span &other);

		unsigned int amount();
		void 	addRandomNumbers(unsigned int quantity);
		void 	addNumber(unsigned int number);
		unsigned int 	shortestSpan();
		unsigned int 	longestSpan();

		class fullException: public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "There is no more elements that can be added\n";
				}
		};

		class minimumException: public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "At least two numbers must be added\n";
				}
		};

		template <typename T> void addRange(T begin, T end)
		{
			if (std::distance(begin, end) + storage.size() > _N)
				throw fullException();
			storage.insert(storage.end(), begin, end);
		}
};

#endif
