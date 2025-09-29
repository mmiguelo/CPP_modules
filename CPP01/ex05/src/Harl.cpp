#include "../Harl.hpp"

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
	std::string compare[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funptr[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	for (int i = 0; i < 4; i++)
	{
		if (level.compare(compare[i]) == 0)
			return ((this->*funptr[i])());
	}
	std::cerr << R << level << ": bad test" << RST << std::endl;
	return ;
}
