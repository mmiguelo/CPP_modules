#include "Phonebook.hpp"

int main() {
	Phonebook phonebook;
	std::string command;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.add();
		/* else if (command == "SEARCH")
			phonebook.search();
		else if (command == "EXIT")
			break ; */
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return 0;
}
