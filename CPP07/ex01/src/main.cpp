#include "../inc/iter.hpp"

static void add(int &n)
{
	n++;
}

static void capitalizeStr(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (std::islower(str[i]))
			str[i] = toupper(str[i]);
	}
}

static void capitalizeChar (char& letter)
{
	letter -= 32;
}

static void uncapitalizeStr(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (std::isupper(str[i]))
			str[i] = tolower(str[i]);
	}
}

static void uncapitalizeChar (char& letter)
{
	letter += 32;
}

static void CamelCaseStr(std::string &str)
{
	std::string result;
	bool capitalizeNext = true;
	for (size_t i = 0; i < str.length(); ++i)
    {
        char c = str[i];
        
        if (std::isspace(c))
		{
            capitalizeNext = true;
            continue;
        }
        if (capitalizeNext)
		{
            result += std::toupper(c);
            capitalizeNext = false;
        } 
		else 
            result += std::tolower(c);
    }
	str = result;
}

int main()
{
	int 		intArr[] = {1, 2, 3, 4, 5, 6};
	const int	cIntArr[] = {1, 2, 3};
	char 		charArr[] = {'a', 'b', 'c'};
	std::string	strArr[] = {"One", "tWo", "tHrEe", "FoUR"};
	std::string strArr2[] = {"Hello World", "this is a Test", "cAmEl CaSe", "CPP is fun!"};

	std::cout << BYEL << "\n----TESTS----" << RST << std::endl << std::endl;
	std::cout << CYA "Invalid Pointer: " RST << std::endl;
	::iter((int *)NULL, 1, add);

	std::cout << CYA "\nInvalid Size: " RST << std::endl;
	::iter(intArr, -1, add);
	
	std::cout << CYA "\nIncrement Non-Const Int Array: " RST << std::endl;
	std::cout << BMAG "Before Incrementing:" RST << std::endl;
	::iter(intArr, 6, print);

	::iter(intArr, 6, add);
	std::cout << BMAG "\nAfter Incrementing:" RST << std::endl;
	::iter(intArr, 6, print);

	std::cout << CYA "\nCapitalize Str Array: " RST << std::endl;
	std::cout << BMAG "Before Capitalizing:" RST <<std::endl;
	::iter(strArr, 4, print);

	::iter(strArr, 4, capitalizeStr);
	std::cout << BMAG "\nAfter Capitalizing:" RST <<std::endl;
	::iter(strArr, 4, print);

	::iter(strArr, 4, uncapitalizeStr);
	std::cout << BMAG "\nAfter Uncapitalizing:" RST <<std::endl;
	::iter(strArr, 4, print);

	std::cout << CYA "\nCapitalize Char Array: " RST << std::endl;
	std::cout << BMAG "Before Capitalizing:" << RST <<std::endl;
	::iter(charArr, 3, print);

	::iter(charArr, 3, capitalizeChar);
	std::cout << BMAG "\nAfter Capitalizing:" << RST <<std::endl;
	::iter(charArr, 3, print);

	::iter(charArr, 3, uncapitalizeChar);
	std::cout << BMAG "\nAfter Uncapitalizing:" << RST <<std::endl;
	::iter(charArr, 3, print);

	std::cout << CYA "\nPrinting Const Int Array: " RST << std::endl;
	::iter(cIntArr, 3, print);

	std::cout << CYA "\nPrinting Camel Case String Array: " RST << std::endl;
	std::cout << BMAG "Before:" RST << std::endl;
	::iter(strArr2, 4, print);

	::iter(strArr2, 4, CamelCaseStr);
	std::cout << BMAG "\nAfter:" RST << std::endl;
	::iter(strArr2, 4, print);

	return (0);
}