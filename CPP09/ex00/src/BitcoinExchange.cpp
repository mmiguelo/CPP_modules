#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	loadData("data.csv");
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	_data = other._data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->_data = other._data;
	}
	return *this;
}

// YYYY-MM-DD
// https://www.ibm.com/docs/en/i/7.4.0?topic=functions-strptime-convert-string-datetime
bool BitcoinExchange::isValidDate(const std::string& date)
{
	struct tm time;
	if (!strptime(date.c_str(), "%Y-%m-%d", &time))
		return false;

	if(date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

	//check leap years
	if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[2] = 29;
	
	if (day > daysInMonth[month])
		return false;

	return true;
}

double BitcoinExchange::isValidValue(const std::string& strValue)
{
    std::stringstream ss(strValue);
	double value;
    ss >> value;
    if (ss.fail() || !ss.eof())
    {
		std::cout << "Error: bad input => " << strValue << std::endl;
		return -1;
	}
    if (value < 0.0)
	{
        std::cout << "Error: not a positive number." << std::endl;
		return -1;
	}
    else if (value > 1000.0)
	{
        std::cout << "Error: too large a number." << std::endl;
		return -1;
	}
    return value;
}

void removeWS(std::string& line)
{
    std::string result;
    for (size_t i = 0; i < line.size(); ++i)
    {
        if (!isspace(line[i]))
            result += line[i];
    }
    line = result;
}

//https://cplusplus.com/reference/map/map/
float BitcoinExchange::getExchangeRate(const std::string& date)
{
	std::map<std::string, float>::iterator it = _data.lower_bound(date);
	if (it != _data.end() && it->first == date)
		return it->second;
	if (it == _data.begin())
		return 0;
	--it;
	return it->second;
}

void BitcoinExchange::processInput(char const *filename)
{
	std::ifstream file(filename);
	if(!file.is_open())
		throw couldNotOpenFile();

	std::string line;

	if (!std::getline(file, line) || line != "date | value")
	{
		std::cout << "[" << line << "] size=" << line.size() << std::endl;
		throw std::runtime_error("Error: bad header. Should be \"date | value\"");
	}

	while (std::getline(file, line))
	{
		std::string date, strValue;
		std::istringstream ss(line);
		std::getline(ss, date, '|');
		std::getline(ss, strValue);
		removeWS(date);
		removeWS(strValue);

		if(isValidDate(date) == false)
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		double value;
		value = isValidValue(strValue);
		if (value == -1)
			continue;
		double rate = getExchangeRate(date);
		std::cout << date << " => " << value << " = " << rate * value << std::endl;
	}
	file.close();
}

void BitcoinExchange::loadData(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if(!file.is_open())
		throw couldNotOpenFile();

	std::string line;

	//parse header
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw invalidFormat();

	while (std::getline(file, line))
	{
		std::string date, price;
		std::istringstream data(line);
		std::getline(data, date, ',');
		std::getline(data, price);

		if(!isValidDate(date))
			throw InvalidDateFormat();

		double priceValue;
		std::istringstream priceStream(price);
		if(!(priceStream >> priceValue))
			throw InvalidPriceFormat();
		_data[date] = priceValue;
	}
	file.close();
}