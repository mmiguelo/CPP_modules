#include "../Bureaucrat.hpp"

int main()
{
{
	std::cout << G "--- Creating bureaucrat with valid grade ---" RST << std::endl;
	try
	{
		Bureaucrat Karen("Karen", 75);
		std::cout << Karen << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

{
	std::cout << G "--- Creating bureaucrat with too high grade ---" RST << std::endl;
	try
	{
		Bureaucrat John("John", 0);
		std::cout << John << std::endl; // this line will never be printed because exception will be thrown
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

{
	std::cout << G "--- Creating bureaucrat with too low grade ---" RST << std::endl;
	try
	{
		Bureaucrat Mike("Mike", 151);
		std::cout << Mike << std::endl; // this line will never be printed because exception will be thrown
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

{
	std::cout << G "--- Valid Incrementing and decrementing grade ---" RST << std::endl;
	try
	{
		Bureaucrat Karen("Karen", 75);
		std::cout << Karen << std::endl;
		std::cout << Y "--- Incrementing grade ---" RST << std::endl;
		Karen.incrementGrade();
		std::cout << Karen << std::endl;

		std::cout << Y "--- Decrementing grade ---" RST << std::endl;
		Karen.decrementGrade();
		std::cout << Karen << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

{
	std::cout << G "--- Incrementing grade beyond upper limit ---" RST << std::endl;
	try
	{
		Bureaucrat Alice("Alice", 1);
		std::cout << Alice << std::endl;
		std::cout << Y "--- Incrementing grade ---" RST << std::endl;
		Alice.incrementGrade();
		std::cout << Alice << std::endl; // this line will never be printed because exception will be thrown
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

{
	std::cout << G "--- Decrementing grade beyond lower limit ---" RST << std::endl;
	try
	{
		Bureaucrat Bob("Bob", 150);
		std::cout << Bob << std::endl;
		std::cout << Y "--- Decrementing grade ---" RST << std::endl;
		Bob.decrementGrade();
		std::cout << Bob << std::endl; // this line will never be printed because exception will be thrown
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
	return 0;
}