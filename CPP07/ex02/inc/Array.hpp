#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>
#include <exception>

#define RED   "\033[0;31m"
#define GRN   "\033[0;32m"
#define YEL   "\033[0;33m"
#define BLU   "\033[0;34m"
#define CYA   "\033[0;36m"
#define BMAG  "\033[35;1m"
#define BYEL  "\033[33;1m"
#define RST   "\033[0m"

class ArrayNullException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Array is empty";
				}
		};

template <typename T> class Array
{
	private:
		T*				_array;
		unsigned int	_size;
	public:
		Array() : _array(NULL), _size(0)
		{
			std::cout << GRN << "Default constructor called" << RST << std::endl;
		}

		Array(unsigned int n)
		{
			if (n > 0)
			{
				_array = new T[n]();
				_size = n;
				std::cout << GRN << "Parameterized constructor called" << RST << std::endl;
			}
			else
			{
				_array = NULL;
				_size = 0;
				std::cout << GRN << "Parameterized constructor called with size 0" << RST << std::endl;
			}
		}

		Array(const Array &other) : _size(other._size)
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
			std::cout << GRN << "Copy constructor called" << RST << std::endl;
		}

		~Array()
		{
			delete[] _array;
			std::cout << RED << "Destructor called" << RST << std::endl;
		}

		Array &operator=(const Array &other)
		{
			if (this != &other)
			{
				delete[] _array;
				_size = other._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = other._array[i];
			}
			std::cout << GRN << "Assignment operator called" << RST << std::endl;
			return *this;
		}

		T& operator [] (size_t index) {
			if (_size == 0)
				throw ArrayNullException();
			if (index >= _size)
				throw std::out_of_range("Index is out of range");
			return (_array[index]);
		}
		
		const T& operator [] (size_t index) const {
			if (_size == 0)
				throw ArrayNullException();
			if (index >= _size)
				throw std::out_of_range("Index is out of range");
			return (_array[index]);
		}

		unsigned int size() const {
			return (this->_size);
		}
};

#endif