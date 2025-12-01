#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	data = other.data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->data = other.data;
	}
	return *this;
}

void BitcoinExchange::loadData(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if(!file.is_open())
		throw couldNotOpenFile();
	std::string line;

	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw invalidFormat();

	std::string date, price;
	double priceValue;

	while (std::getline(file, line))
	{
		std::istringstream data(line);
		std::getline(data, date, ',');
		std::getline(data, price);

		if(!isValidDate(date))
			throw InvalidDateFormat();
		
	}
}