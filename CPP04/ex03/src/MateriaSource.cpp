#include "../MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << Y << "MateriaSource: Default constructor called" << RST << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource &other)
{
	std::cout << Y << "MateriaSource: Copy constructor called" << RST << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other._materias[i])
			this->_materias[i] = other._materias[i]->clone();
		else
			this->_materias[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource &other)
{
	std::cout << Y << "MateriaSource: Copy assignment operator called" << RST << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (other._materias[i])
				this->_materias[i] = other._materias[i]->clone();
			else
				this->_materias[i] = NULL;
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
		{
			delete this->_materias[i];
			this->_materias[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
	{
		std::cout << R << "MateriaSource: Cannot learn null materia" << RST << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->_materias[i])
		{
			this->_materias[i] = materia->clone();
			std::cout << G << "MateriaSource: Learned materia of type " << materia->getType() << RST << std::endl;
			delete materia;
			return ;
		}
	}
	std::cout << R << "MateriaSource: Materia source is full, cannot learn new materia" << RST << std::endl;
	delete materia;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] && this->_materias[i]->getType() == type)
		{
			std::cout << G << "MateriaSource: Created materia of type " << type << RST << std::endl;
			return this->_materias[i]->clone();
		}
	}
	std::cout << R << "MateriaSource: Type: " << type << " not recognized. Try learn it first" << RST << std::endl;
	return NULL;
}
