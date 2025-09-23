#include "../headers/Phonebook.hpp"

std::string tabToSpace(std::string str)
{
	for(int i = 0; str[i]; i++)
	{
		if (str[i] == '\t')
			str[i] = ' ';
	}
	return (str);
}

int main() {
	Phonebook phonebook;
	std::string command;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::clearerr(stdin);
			std::cin.clear();
			return 0;
		}
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return 0;
}
