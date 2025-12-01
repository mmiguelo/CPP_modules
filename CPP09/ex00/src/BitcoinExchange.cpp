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

bool isValidDate(std::string date)
{
	if(date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for(int i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	return true;
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