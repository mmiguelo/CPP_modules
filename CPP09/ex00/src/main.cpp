#include "../inc/BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
			throw std::runtime_error("Error: invalid number of arguments. Usage: ./btc <input_file>\n");
	try
	{
		BitcoinExchange btcExchange;
		btcExchange.processInput(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}