#include "../inc/RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN& other) { (void)other; }
RPN& RPN::operator=(const RPN& other) 
{ 
	(void)other; 
	return *this; 
}

int RPN::evaluate(const std::string& expression)
{
	std::istringstream iss(expression);
	std::string token;

	std::stack<int> stk;
	while (iss >> token)
	{
		int 
	}
}