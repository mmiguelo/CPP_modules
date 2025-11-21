#pragma once

#include "AForm.hpp"
#include <string>
#include <cstdlib>
#include <ctime>

#define RED   "\033[0;31m"
#define GRN   "\033[0;32m"
#define YEL   "\033[0;33m"
#define BLU   "\033[0;34m"
#define CYA   "\033[0;36m"
#define BMAG  "\033[35;1m"
#define BYEL  "\033[33;1m"
#define RST   "\033[0m"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	std::string getTarget() const;
	void execute(Bureaucrat const &executor) const;
};