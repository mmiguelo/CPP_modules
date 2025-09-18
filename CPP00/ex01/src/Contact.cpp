#include "Contact.hpp"

Contact::Contact()
{
	std::cout << "Class Contact was created" << std::endl;
}

Contact::~Contact()
{
	std::cout << "Class Contact was destroyed" << std::endl;
}


void Contact::setFirstName(std::string str) {
	_firstName = str;
}

std::string Contact::getFirstName() {
	return _firstName;
}
