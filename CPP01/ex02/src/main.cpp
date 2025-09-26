#include <iostream>
#include <string>
#include <iomanip>

int	main()
{
	std::string string = "HI THIS IS BRAIN"; //guarda a frase na memoria
	std::string *stringPTR = &string; //guarda o endereco de string
	std::string &stringREF = string; // apenas uma referencia para string
	std::cout << "Memory address of the string variable: " << &string << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << "Value of the string variable: " << string << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
	return (0);
}
