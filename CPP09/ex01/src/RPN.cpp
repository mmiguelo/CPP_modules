#include "../inc/RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN& other) { (void)other; }
RPN& RPN::operator=(const RPN& other) 
{ 
	(void)other; 
	return *this; 
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::evaluate(const std::string& expression)
{
	std::istringstream iss(expression);
	std::string token;
	std::stack<int> stk;

	while (iss >> token)
	{
		if (token.length() != 1)
			throw std::runtime_error("Error: invalid input");

		char c = token[0];

		if (isdigit(c))
			stk.push(c - '0');
		else if (isOperator(c))
		{
			if (stk.size() < 2)
				throw std::runtime_error("Error: not enough numbers for operator");

			int b = stk.top();
			stk.pop();
			int a = stk.top();
			stk.pop();

			switch (c)
			{
				case '+':
				{
					stk.push(a + b);
					break;
				}
				case '-':
				{
					stk.push(a - b);
					break;
				}
				case '*':
				{
					stk.push(a * b);
					break;
				}
				case '/':
				{
					if (b == 0)
						throw std::runtime_error("Error: division by zero");
					stk.push(a / b);
					break;
				}
			}
		}
		else
			throw std::runtime_error("Error: unknown token");
	}
	if (stk.size() != 1)
        throw std::runtime_error("Error: invalid expression");
	return (stk.top());
};