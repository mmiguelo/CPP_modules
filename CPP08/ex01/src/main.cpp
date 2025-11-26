#include "span.hpp"

int main()
{
	{
		std::cout << B << "----- Test 1: Adding more numbers than capacity -----" << RST << std::endl;
		span sp = span(4);

		sp.addNumber(1);
		sp.addNumber(4);
		sp.addNumber(8);
		sp.addNumber(9);
		try {
			std::cout << "Adding another number..." << std::endl;
			sp.addNumber(15); // This should throw an exception
		} catch (const std::exception &e) {
			std::cout << R << e.what() << RST;
		}
	}
	{
		std::cout << B << "----- Test 2: Calculating spans with insufficient numbers -----" << RST << std::endl;
		span sp = span(3);

		sp.addNumber(5);
		try {
			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cout << R << e.what() << RST;
		}
	}
	{
		std::cout << B << "----- Test 3: Normal operation -----" << RST << std::endl;

		span sp = span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	{
		std::cout << B << "----- Test 4: Adding random numbers -----" << RST << std::endl;

		span sp = span(10000);
		std::cout << "Span size: " << sp.amount() << std::endl;
		sp.addNumber(rand());
		std::cout << "Span size: " << sp.amount() << std::endl;	
		sp.addNumber(rand());
		std::cout << "Span size: " << sp.amount() << std::endl;
		sp.addNumber(rand());
		std::cout << "Span size: " << sp.amount() << std::endl;
		sp.addRandomNumbers(500);
		std::cout << "Span size: " << sp.amount() << std::endl;

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	return 0;
}