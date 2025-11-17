#include "../Form.hpp"

Form::Form(): _name("Unkown"), _signed(false), _signGrade(150), _executeGrade(150)
{
	//std::cout << G << "Form default constructor called" << RST << std::endl;
}

Form::Form(const std::string &name, int signGrade, int executeGrade) : _name(name),
																		_signed(false),
																		_signGrade(signGrade),
																		_executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	//std::cout << G << "Form parameterized constructor called" << RST << std::endl;
}

Form::Form(const Form &other) : _name(other._name),
							_signed(other._signed),
							_signGrade(other._signGrade),
							_executeGrade(other._executeGrade)
{
	//std::cout << G << "Form copy constructor called" << RST << std::endl;
}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
		this->_signed = other._signed;
	return *this;
	//std::cout << G << "Form copy assignment operator called" << RST << std::endl;
}

