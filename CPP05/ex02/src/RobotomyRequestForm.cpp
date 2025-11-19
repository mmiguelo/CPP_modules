#include "../RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
					: AForm("Undefined", 72, 45), _target("Undefined")
{
	std::cout << GRN << "RobotomyRequestForm Default constructor called" << RST << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
					: AForm(target, 72, 45), _target(target)
{
	std::cout << GRN << "RobotomyRequestForm Parameterized constructor called" << RST << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
					: AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade()), _target(other._target)
{
	std::cout << GRN << "RobotomyRequestForm Copy constructor called" << RST << std::endl;
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm Destructor called" << RST << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		this->_target = other.getTarget();
	}
	return *this;
	std::cout << YEL << "RobotomyRequestForm Copy assignment operator called" << RST << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void RobotomyRequestForm::execute() const
{
	std::cout << "Bzzzzzz... Vrrrrrr..." << std::endl;
	if (std::rand() & 1)
		std::cout << GRN << this->_target << " has been robotomized successfully." << RST << std::endl;
	else
		std::cout << RED << "Robotomy failed on " << this->_target << "." << RST << std::endl;
}