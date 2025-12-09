#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <exception>

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		int evaluate(const std::string& expression);
	private:
}