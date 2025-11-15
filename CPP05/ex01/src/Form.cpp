#include "Form.hpp"

Form::Form(): _name("Unkown"), _signed(false), _signGrade(150), _executeGrade(150)
{
	std::cout << G << "Form default constructor called" << RST << std::endl;
}	