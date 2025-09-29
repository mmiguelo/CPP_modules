#include "../Harl.hpp"

Harl::Harl()
{
	this->type["DEBUG"] = &Harl::debug;
	this->type["INFO"] = &Harl::info;
	this->type["WARNING"] = &Harl::warning;
	this->type["ERROR"] = &Harl::error;
}

Harl::~Harl()
{}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-";
	std::cout << "pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't";
	std::cout << "put enough bacon in my burger! If you did, I wouldn't be asking for more!";
	std::cout << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for";
	std::cout << "years, whereas you started working here just last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	try
	{
		(this->*type.at(level))();
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << R << level << ": bad test" << RST << std::endl;
	}
	
}

int getLevel(std::string &level)
{
	if (level == "DEBUG")
		return DEBUG;
	else if (level == "INFO")
		return INFO;
	else if (level == "WARNING")
		return WARNING;
	else if (level == "ERROR")
		return ERROR;
	else
		return INVALID;
}

void Harl::filter(std::string level)
{
	int filter = getLevel(level);
	switch (filter)
	{
	case DEBUG:
		std::cout << G << "\n[DEBUG]" << RST << std::endl;
		this->debug();
		std::cout << G << "\n[INFO]" << RST << std::endl;
		this->info();
		std::cout << G << "\n[WARNING]" << RST << std::endl;
		this->warning();
		std::cout << G << "\n[ERROR]" << RST << std::endl;
		this->error();
		break;
	case INFO:
		std::cout << G << "\n[INFO]" << RST << std::endl;
		this->info();
		std::cout << G << "\n[WARNING]" << RST << std::endl;
		this->warning();
		std::cout << G << "\n[ERROR]" << RST << std::endl;
		this->error();
		break;
	case WARNING:
		std::cout << G << "\n[WARNING]" << RST << std::endl;
		this->warning();
		std::cout << G << "\n[ERROR]" << RST << std::endl;
		this->error();
		break;
	case ERROR:
		std::cout << G << "\n[ERROR]" << RST << std::endl;
		this->error();
		break;
	default:
		std::cout << R << "[ Probably complaining about insignificant problems ]" << RST << std::endl;
		break;
	}
}