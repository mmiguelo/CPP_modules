#include "../Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150)
{
	std::cout << G << "Bureaucrat default constructor called" << RST << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
	std::cout << G << "Bureaucrat: " << this->_name << " constructor called, with grade: " << this->_grade << RST << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << G << "Bureaucrat copy constructor called" << RST << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	std::cout << G << "Bureaucrat copy assignment operator called" << RST << std::endl;
	return *this;
}

Bureaucrat:: ~Bureaucrat()
{
	std::cout << R << "Bureaucrat destructor called" << RST << std::endl;
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


void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << G << this->_name << " signed " << form.getName() << RST << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << R << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << RST << std::endl;
	}
}