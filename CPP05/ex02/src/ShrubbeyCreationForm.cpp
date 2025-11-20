#include "../ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Undefined", 145, 137), _target("Undefined")
{
	std::cout << GRN << "ShrubberyCreationForm Default constructor called" << RST << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target, 145, 137), _target(target)
{
	std::cout << GRN << "ShrubberyCreationForm Parameterized constructor called" << RST << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
					: AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade()), _target(other._target)
{
	std::cout << GRN << "ShrubberyCreationForm Copy constructor called" << RST << std::endl;
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm Destructor called" << RST << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		this->_target = other.getTarget();
	}
	return *this;
	std::cout << YEL << "ShrubberyCreationForm Copy assignment operator called" << RST << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getSigned())
		throw AForm::GradeTooLowException();
	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();
	std::string fileName = this->_target + "_shrubbery";
	std::ofstream outfile(fileName.c_str());
	if (!outfile)
	{
		std::cerr << RED << "Error: Could not create file." << RST << std::endl;
		return;
	}
	outfile << "       _-_\n"
			   "    /~~   ~~\\\n"
			   " /~~         ~~\\\n"
			   "{               }\n"
			   " \\  _-     -_  /\n"
			   "   ~  \\\\ //  ~\n"
			   "_- -   | | _- _\n"
			   "  _ -  | |   -_\n"
			   "      // \\\\\n";
	outfile.close();
	std::cout << GRN << "Shrubbery created at " << this->_target + "_shrubbery" << RST << std::endl;
}