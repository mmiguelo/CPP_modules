#include "../inc/easyfind.hpp"
#include <vector>
#include <list>

int main(void)
{
	{
		std::vector<int> container;
		for (int i = 0; i < 10; i++)
			container.push_back(i);
		try
		{
			easyfind(container, 5);
			easyfind(container, 10);
		}
		catch (std::exception &e)
		{
			std::cout << R << e.what() << RST << std::endl;
		}
	}
    {
		std::list<int> container;
		container.push_back(137);
        container.push_back(598);
        container.push_back(942);
        container.push_back(0);
        container.push_back(-627);
        container.push_back(56);
        container.push_back(23);
		try
		{
			easyfind(container, 137);
			easyfind(container, 100);
		}
		catch (std::exception &e)
		{
			std::cout << R << e.what() << RST << std::endl;
		}
	}
	return 0;
}