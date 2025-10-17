#include "../MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << Y << "MateriaSource: Default constructor called" << RST << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << Y << "MateriaSource: Copy constructor called" << RST << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other._materias[i])
			this->_materias[i] = other._materias[i]->clone();
		else
			this->_materias[i] = nullptr;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << Y << "MateriaSource: Copy assignment operator called" << RST << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->_materias[i];
			if (other._materias[i])
				this->_materias[i] = other._materias[i]->clone();
			else
				this->_materias[i] = nullptr;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << Y << "MateriaSource: Destructor called" << RST << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{}