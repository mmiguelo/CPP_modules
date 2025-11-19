#include "../Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150)
{
	std::cout << GRN << "Bureaucrat default constructor called" << RST << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
	std::cout << GRN << "Bureaucrat parameterized constructor called" << RST << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << GRN << "Bureaucrat copy constructor called" << RST << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	std::cout << GRN << "Bureaucrat copy assignment operator called" << RST << std::endl;
	return *this;
}

Bureaucrat:: ~Bureaucrat()
{
	std::cout << RED << "Bureaucrat destructor called" << RST << std::endl;
}

const std::string& Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
}

std::ostream& operator << (std::ostream& output, const Bureaucrat& b)
{
	output << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return output;
}


void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << GRN << this->_name << " signed " << form.getName() << RST << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << RST << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try 
	{
		form.execute(*this);
		std::cout << GRN << getName() << " executed " << form.getName() << RST << std::endl;
	} 
	catch (std::exception& error) 
	{
		std::cout << RED << getName() << " couldn't execute " << form.getName()
					<< " because " << error.what() << RST << std::endl;
	}
}