#pragma once

#include "IMateriaSource.hpp"
#include <string>
#include <iostream>

#define R		"\033[0;31m" //RED
#define G		"\033[0;32m" //GREEN
#define Y		"\033[0;33m" //YELLOW
#define B		"\033[0;34m" //BLUE
#define RST		"\033[0m"   //RESET

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _materias[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource &other);
		MateriaSource &operator=(MateriaSource &other);
		~MateriaSource();

		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const & type);
};