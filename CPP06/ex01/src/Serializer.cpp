#include "../Serializer.hpp"

Serializer::Serializer()
{
	std::cout << G << "Serializer: defualt constructor called" << RST << std::endl;
}  // Default constructor

Serializer::~Serializer()
{
	std::cout << R << "Serializer: destructor called" << RST << std::endl;
} // Destructor

Serializer::Serializer(const Serializer &other)
{
    *this = other;
    std::cout << G << "Serializer: Copy constructor called." << RST << std::endl;
}

Serializer& Serializer::operator=(const Serializer &other) {
    if (this != &other)
        *this = other;
    std::cout << G << "Copy assignment operator called" << RST << std::endl;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t newType = reinterpret_cast<uintptr_t>(ptr);
    return newType;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* newType = reinterpret_cast<Data*>(raw);
    return newType;
}