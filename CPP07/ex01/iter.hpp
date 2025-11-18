#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

#define R		"\033[0;31m" //RED
#define G		"\033[0;32m" //GREEN
#define Y		"\033[0;33m" //YELLOW
#define B		"\033[0;34m" //BLUE
#define RST		"\033[0m"   //RESET

template <typename T> void iter(T *array, const size_t length, void (*f)(T &))
{
	if (length == 0)
	{
		std::cerr << R << "Error: Array length is zero." << RST << std::endl;
		return ;
	}
	if (!array)
	{
		std::cerr << R << "Error: Null array pointer." << RST << std::endl;
		return ;
	}
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}


#endif