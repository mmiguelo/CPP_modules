#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>

class BitcoinExchange
{
	private:

		std::map<std::string, float> _data;
		void loadData(const std::string& filename);
		bool isValidDate(const std::string& date);
		double isValidValue(const std::string& strValue);

		void processInput(char const *filename);
		
	public:

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		float getExchangeRate(const std::string& date, double value);

		class couldNotOpenFile : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Error: could not open file.\n";
				}
		};

		class invalidFormat : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Error: invalid format.\nCorret format: data,exchange_rate\n";
				}
		};

		class InvalidDateFormat : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Invalid date format. Expected 'YYYY-MM-DD'");
				}
		};

		class InvalidPriceFormat : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Invalid price format. Expected a number between 0.00 and 1000.00");
				}
		};
};