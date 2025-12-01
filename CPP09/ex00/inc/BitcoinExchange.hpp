#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void loadData(const std::string& filename);
		void processInput(const std::string& filename);

   	private:
		std::map<std::string, float> data;

		bool isValidDate(const std::string& date);
		bool isValidValue(const std::string& valueStr, float& value);
		float getExchangeRate(const std::string& date);

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
					return ("Invalid price format. Expected a number between 0.0 and 1000.0");
				}
		};
};