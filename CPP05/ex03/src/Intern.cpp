#include "../Intern.hpp"

Intern::Intern()
{
	std::cout << G << "Intern: default constructor called" << RST << std::endl;
}  // Default constructor

Intern::~Intern()
{
	std::cout << R << "Intern: destructor called" << RST << std::endl;
} // Destructor

Intern::Intern(const Intern &other)
{
    *this = other;
    std::cout << G << "Intern: Copy constructor called." << RST << std::endl;
}

Intern& Intern::operator=(const Intern &other) {
    if (this != &other)
        *this = other;
    std::cout << G << "Copy assignment operator called" << RST << std::endl;
    return *this;
}

AForm * Intern::makeForm(std::string formName, std::string formTarget)
{
    int ID = -1;
    std::string form[3] = {"shrubbery creation", "robotomy request", "presidential form"};

    if (formTarget.empty())
        throw Intern::EmptyTarget();

    for(int i = 0; i < 3; i++)
    {
        if (form[i] == formName)
        {
            ID = i;
            break;
        }
    }
    if (ID != -1)
        std::cout << "Intern creates " << formName << std::endl;

    switch (ID)
    {
        case 0:
            return (new ShrubberyCreationForm(formTarget));
        case 1:
            return (new RobotomyRequestForm(formTarget));
        case 2:
            return (new PresidentialPardonForm(formTarget));
        default:
            throw Intern::WrongForm();
    }
}