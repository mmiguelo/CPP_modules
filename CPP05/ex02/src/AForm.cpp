#include "AForm.hpp"

AForm::AForm(): _name("Default"), _signed(false), _signGrade(150), _executeGrade(150)
{
	std::cout << G << "AForm Default constructor called" << RST << std::endl;
}

AForm::AForm(const std::string &name, int signGrade, int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
	std::cout << G << "AForm Parameterized constructor called" << RST << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	std::cout << G << "AForm Copy constructor called" << RST << std::endl;
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_signed = other._signed;
	std::cout << G << "AForm Assignment operator called" << RST << std::endl;
	return *this;
}

AForm::~AForm()
{
	std::cout << R << "AForm Destructor called" << RST << std::endl;
}

const std::string &AForm::getName() const
{
	return this->_name;
}

int AForm::getSignGrade() const
{
	return this->_signGrade;
}

int AForm::getExecuteGrade() const
{
	return this->_executeGrade;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

void AForm::setSigned(bool sign)
{
	this->_signed = sign;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (this->_signed)
		throw AForm::AlreadySignedException();
	if (b.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "Form " << form.getName() << " details:" << std::endl;
	out << "Signed: " << (form.getSigned() ? "Yes" : "No") << std::endl;
	out << "Sign Grade: " << form.getSignGrade() << std::endl;
	out << "Execute Grade: " << form.getExecuteGrade() << std::endl;
	return out;
}