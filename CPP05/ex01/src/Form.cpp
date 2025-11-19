#include "../Form.hpp"

Form::Form(): _name("Unkown"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
	std::cout << G << "Form default constructor called" << RST << std::endl;
}

Form::Form(const std::string &name, int signGrade, int executeGrade) : _name(name),
																		_isSigned(false),
																		_signGrade(signGrade),
																		_executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	std::cout << G << "Form parameterized constructor called" << RST << std::endl;
}

Form::Form(const Form &other) : _name(other._name),
							_isSigned(other._isSigned),
							_signGrade(other._signGrade),
							_executeGrade(other._executeGrade)
{
	std::cout << G << "Form copy constructor called" << RST << std::endl;
}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
	std::cout << G << "Form copy assignment operator called" << RST << std::endl;
}

Form::~Form()
{
	std::cout << R << "Form destructor called" << RST << std::endl;
}

const std::string &Form::getName() const
{
	return this->_name;
}

int Form::getSignGrade() const
{
	return this->_signGrade;
}

int Form::getExecuteGrade() const
{
	return this->_executeGrade;
}

bool Form::getSigned() const
{
	return this->_isSigned;
}

void Form::setSigned(bool sign)
{
	this->_isSigned = sign;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (this->_isSigned)
		throw AlreadySignedException();
	else if(b.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	setSigned(true);
	std::cout << B << "Bureaucrat " << b.getName() << " signed form " << this->getName() << RST << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName() << " details:" << std::endl;
	out << "Signed: " << (form.getSigned() ? "Yes" : "No") << std::endl;
	out << "Sign Grade: " << form.getSignGrade() << std::endl;
	out << "Execute Grade: " << form.getExecuteGrade() << std::endl;
	return out;
}
