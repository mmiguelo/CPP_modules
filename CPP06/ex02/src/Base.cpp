#include "../Base.hpp"
#include "../A.hpp"
#include "../B.hpp"
#include "../C.hpp"

Base::~Base()
{
	std::cout << R << "Base: destructor called" << RST << std::endl;
} // Destructor

Base* generate(void)
{
    int random = std::rand() % 3;
    switch (random)
    {
    case 0:
        std::cout << G << "Generated A instance class" << RST << std::endl;
        return new A();
    case 1:
        std::cout << G << "Generated B instance class" << RST << std::endl;
        return new B();
    case 2:
        std::cout << G << "Generated C instance class" << RST << std::endl;
        return new C();
    default:
        std::cout << R << "Error generating instance class" << RST << std::endl;
        return NULL;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << Y << "Identified A instance class" << RST << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << Y << "Identified B instance class" << RST << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << Y << "Identified C instance class" << RST << std::endl;
    else
        std::cout << R << "Unknown instance class" << RST << std::endl;
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << Y << "Identified A instance class" << RST <<std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << Y << "Identified B instance class" << RST << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << Y << "Identified C instance class" << RST << std::endl;
        return;
    } catch (...) {}

    std::cout << R << "Unknown instance class" << RST << std::endl;
}
