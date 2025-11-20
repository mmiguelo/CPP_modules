#include "../PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
					: AForm("Undefined", 25, 5), _target("Undefined")
{
	std::cout << GRN << "PresidentialPardonForm Default constructor called" << RST << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
					: AForm(target, 25, 5), _target(target)
{
	std::cout << GRN << "PresidentialPardonForm Parameterized constructor called" << RST << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
					: AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade()), _target(other._target)
{
	std::cout << GRN << "PresidentialPardonForm Copy constructor called" << RST << std::endl;
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm Destructor called" << RST << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		this->_target = other.getTarget();
	}
	return *this;
	std::cout << YEL << "PresidentialPardonForm Copy assignment operator called" << RST << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!getSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > getExecuteGrade())
        throw AForm::GradeTooLowException();

    std::cout << "Just to inform that " << this->_target 
              << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}