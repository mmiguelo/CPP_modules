#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

#define RED   "\033[0;31m"
#define GRN   "\033[0;32m"
#define YEL   "\033[0;33m"
#define BLU   "\033[0;34m"
#define CYA   "\033[0;36m"
#define BMAG  "\033[35;1m"
#define BYEL  "\033[33;1m"
#define RST   "\033[0m"

template <typename T> void iter(T *array, const int length, void (*f)(T &))
{

	if (!array)
	{
		std::cerr << RED << "Error: Null array pointer." << RST << std::endl;
		return ;
	}
	if (length < 1)
	{
		std::cerr << RED << "Error: Array length must be a positive integer." << RST << std::endl;
		return ;
	}
	for (int i = 0; i < length; i++)
		f(array[i]);
}

template <typename T> void iter(const T *array, const int length, void (*f)(const T &))
{
	if (!array)
	{
		std::cerr << RED << "Error: Null array pointer." << RST << std::endl;
		return ;
	}
	if (length < 1)
	{
		std::cerr << RED << "Error: Array length must be a positive integer." << RST << std::endl;
		return ;
	}
	for (int i = 0; i < length; i++)
		f(array[i]);
}

template <typename T> void print(const T& arg)
{
	std::cout << arg << std::endl;
}

#endif