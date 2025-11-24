#include "../Bureaucrat.hpp"
#include "../Intern.hpp"
#include "../PresidentialPardonForm.hpp"
#include "../RobotomyRequestForm.hpp"
#include "../ShrubberyCreationForm.hpp"

int main()
{
    srand(time(NULL));

	std::cout << BMAG << "\n	Bureaucrat, Intern and Form Creation\n" << RST;
	Bureaucrat nor("Norris", 1);
	Intern newIntern;
	AForm* form1;
	AForm* form2;
	AForm* form3;
	AForm* form4;
    AForm* form5;

	std::cout << BMAG << "\n	Intern Makes Forms\n" << RST;
	try {
		form1 = newIntern.makeForm("weird name", "target");
	} catch (std::exception& error) {
		std::cout << RED << error.what() << RST << std::endl;
		form1 = NULL;
	}
	std::cout << std::endl;

    try {
        form5 = newIntern.makeForm("shrubbery creation", "");
    } catch (std::exception& error) {
        std::cout << RED << error.what() << RST << std::endl;
        form5 = NULL;
    }
    std::cout << std::endl;

	try {
		form2 = newIntern.makeForm("shrubbery creation", "shrub");
		nor.signForm(*form2);
		nor.executeForm(*form2);
	} catch (std::exception& error) {
		std::cout << RED << error.what() << RST << std::endl;
		form2 = NULL;
	}
	std::cout << std::endl;

	try {
		form3 = newIntern.makeForm("robotomy request", "robot");
		nor.signForm(*form3);
		nor.executeForm(*form3);
	} catch (std::exception& error) {
		std::cout << RED << error.what() << RST << std::endl;
		form3 = NULL;
	}
	std::cout << std::endl;

	try {
		form4 = newIntern.makeForm("presidential pardon", "pardon");
		nor.signForm(*form4);
		nor.executeForm(*form4);
	} catch (std::exception& error) {
		std::cout << RED << error.what() << RST << std::endl;
		form4 = NULL;
	}
	std::cout << std::endl;

	std::cout << BMAG << "	Destruction\n" << RST;
	if (form1) delete form1;
	if (form2) delete form2;
	if (form3) delete form3;
	if (form4) delete form4;
    if (form5) delete form5;
	return (0);
}