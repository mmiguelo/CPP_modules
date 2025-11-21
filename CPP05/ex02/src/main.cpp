#include "../Bureaucrat.hpp"
#include "../PresidentialPardonForm.hpp"
#include "../RobotomyRequestForm.hpp"
#include "../ShrubberyCreationForm.hpp"

int main()
{
	std::srand(std::time(NULL));

	std::cout << BMAG << "\n	Bureaucrat Creation\n" << RST;
	Bureaucrat nor("Norris", 2);
	Bureaucrat rus("Russel", 40);
	Bureaucrat ant("Antonelli", 100);
	Bureaucrat lat("Latifi", 150);
	try
	{
		Bureaucrat person("person", 0);
	}
	catch (std::exception& error)
	{
		std::cout << error.what() << std::endl;
	}

	std::cout << BMAG << "\n	Form Creation and << operator\n" << RST;
	ShrubberyCreationForm shrub("shrub");
	std::cout << shrub << std::endl;
	RobotomyRequestForm robot("robot");
	std::cout << robot << std::endl;
	PresidentialPardonForm pardon("pardon");
	std::cout << robot << std::endl;

	std::cout << BMAG << "	Polymorphism test\n" << RST;
	AForm* form1 = new PresidentialPardonForm("pardon");
	std::cout << *form1 << std::endl;

	std::cout << BMAG << "	Shrubbery Form Execution\n" << RST;
	try 
	{
		nor.executeForm(shrub);
	} 
	catch (std::exception& error) 
	{
		std::cout << error.what() << std::endl;
	}
	std::cout << std::endl;

	try 
	{
		nor.signForm(shrub);
		nor.executeForm(shrub);
	} 
	catch (std::exception& error) 
	{
		std::cout << error.what() << std::endl;
	}
	std::cout << std::endl;

	try 
	{
		lat.signForm(shrub);
		lat.executeForm(shrub);
	} 
	catch (std::exception& error) 
	{
		std::cout << error.what() << std::endl;
	}
	std::cout << std::endl;

	try 
	{
		ant.signForm(shrub);
		ant.executeForm(shrub);
	} 
	catch (std::exception& error) 
	{
		std::cout << error.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << BMAG << "	Robotomy Form Execution\n" << RST;
	for (int i = 0; i < 6; i++)
	{
		try {
			nor.signForm(robot);
			nor.executeForm(robot);
		} 
		catch (std::exception& error) 
		{
			std::cout << error.what() << std::endl;
		}
	}
	std::cout << std::endl;

	try 
	{
		rus.signForm(robot);
		rus.executeForm(robot);
	} 
	catch (std::exception& error) 
	{
		std::cout << error.what() << std::endl;
	}
	std::cout << std::endl;

	try 
	{
		lat.signForm(robot);
		lat.executeForm(robot);
	}
	catch (std::exception& error) 
	{
		std::cout << error.what() << std::endl;
	}
	std::cout << std::endl;

	try 
	{
		ant.signForm(robot);
		ant.executeForm(robot);
	} 
	catch (std::exception& error) 
	{
		std::cout << error.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << BMAG << "	Presidential Form Execution\n" << RST;
	try 
	{
		lat.signForm(pardon);
		lat.executeForm(pardon);
	} 
	catch (std::exception& error) 
	{
		std::cout << error.what() << std::endl;
	}
	std::cout << std::endl;

	try 
	{
		nor.signForm(pardon);
		nor.executeForm(pardon);
	} 
	catch (std::exception& error) 
	{
		std::cout << error.what() << std::endl;
	}
	std::cout << std::endl;

	try 
	{
		rus.signForm(pardon);
		rus.executeForm(pardon);
	} 
	catch (std::exception& error) 
	{
		std::cout << error.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << BMAG << "	Destruction\n" << RST;
	delete form1;
	return (0);
}