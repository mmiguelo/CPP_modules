#include "MutantStack.hpp"

int subjectmain()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17); // ads element to the end of the container
	std::cout << mstack.top() << std::endl;
	mstack.pop(); // removes last element inserted
	std::cout << mstack.size() << std::endl; // numer of elements in the container
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl; //std::cout << *it << " ";
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

int mymain()
{
	std::vector<int> vector;
	vector.push_back(5);
	vector.push_back(17); // ads element to the end of the container
	std::cout << vector.back() << std::endl;
	vector.pop_back(); // removes last element inserted
	std::cout << vector.size() << std::endl; // numer of elements in the container
	vector.push_back(3);
	vector.push_back(5);
	vector.push_back(737);
	//[...]
	vector.push_back(0);
	std::vector<int>::iterator it = vector.begin();
	std::vector<int>::iterator ite = vector.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl; //std::cout << *it << " ";
		++it;
	}
	return 0;
}

int main()
{
	std::cout << B << "Main from the subject: \n" << RST;
	subjectmain();
	std::cout << B << "\nSame main but with container vector: \n" << RST;
	mymain();
	std::cout << B << "\n Other tests:\n" << RST;
	std::cout << G << "Creating Stack\n" << RST;
	MutantStack<int> s;
	std::cout << G << "Testing if stack is empty: " << (s.empty() ? "True" : "False") << "\n" << RST;
	std::cout << G << "Adding 5 random numbers\n" << RST;
	for (int i = 0; i < 5; i++)
	{
		s.push(rand() % 10000);
		std::cout << "Added " << i+1 << "º number: " << s.top() << " to the stack" << std::endl;
	}
	std::cout << G << "Testing if stack is empty: " << (s.empty() ? "True" : "False") << "\n" << RST;
	std::cout << B << "\nIterators: \n" << RST;
	MutantStack<int>::iterator it = s.begin();
	MutantStack<int>::iterator ite = s.end();
	std::cout << Y << "first element of the stack: " << RST << *it << std::endl;
	std::cout << Y << "last element of the stack: " << RST << *(ite - 1) << std::endl;
	std::cout << B << "incrementing and decrementing iterators: \n" << RST;
	std::cout << G << "incrementing first element position \n" << RST;
	it++;
	std::cout << Y << "new first element of the stack: " << RST << *it << std::endl;
	std::cout << G << "decrementing last element position \n" << RST;
	ite--;
	std::cout << Y << "new last element of the stack: " << RST << *(ite - 1) << std::endl;
	it--;
	ite++;
	std::cout << B << "Reordering and pop elements\n" << RST;
	std::cout << R << "Pop elements:\n" << RST;
	std::cout << Y << "Before popping:\n" << RST;
	std::cout << Y << "Stack size: " << s.size() <<"\n" << RST;
	int i = 0;
	while (it != ite)
	{
		std::cout << *it << " " << std::endl;
		++it;
		i++;
	}
	std::cout << Y << "After popping:\n" << RST;
	s.pop();
	std::cout << Y << "Stack size: " << s.size() <<"\n" << RST;
	it = s.begin();
	ite = s.end();
	i = 0;
	while (it != ite)
	{
		std::cout << *it << " " << std::endl;
		i++;
		++it;
	}
}