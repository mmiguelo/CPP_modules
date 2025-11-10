#include "../Character.hpp"
#include "../ICharacter.hpp"

Character::Character() : _name("Default"), _droped_count(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		droped[i] = NULL;
	std::cout << G << "Character: default constructor called" << RST << std::endl;
}

Character::Character(std::string const & name) : _name(name), _droped_count(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		droped[i] = NULL;
	std::cout << G << "Character: Parameterized constructor called" << RST << std::endl;
}

Character::Character(const Character &other) : _droped_count(0)
{
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
		for (int i = 0; i < 100; i++)
			this->droped[i] = NULL;
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (this->droped[i])
		{
			delete this->droped[i];
			this->droped[i] = NULL;
		}
	}
	std::cout << G << "Character: destructor called" << RST << std::endl;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
			{
				delete this->inventory[i];
				this->inventory[i] = NULL;
			}
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
		for (int i = 0; i < 100; i++)
		{
			if (this->droped[i])
			{
				delete this->droped[i];
				this->droped[i] = NULL;
			}
		}
		this->_droped_count = 0;
	}
	return *this;
}

void Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << R << "Character: Cannot equip null materia" << RST << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			std::cout << G << "Character: Equipped materia of type " << m->getType() << " in slot " << i << RST << std::endl;
			return ;
		}
	}
	std::cout << Y << "Character: Inventory full, cannot equip materia of type " << m->getType() << RST << std::endl;
}

void Character::unequip(int index)
{
	if(!this->inventory[index])
	{
		std::cout << Y << "Character: No materia to unequip in slot " << index << RST << std::endl;
		return;
	}
	if (index >= 0 && index < 4 && this->inventory[index])
	{
		if (_droped_count < 100)
		{
			this->droped[_droped_count++] = this->inventory[index];
			this->inventory[index] = NULL;
			std::cout << G << "Character: Unequipped materia from slot " << index << " and droped on the floor" << RST << std::endl;
			return ;
		}
		std::cout << R << "Character: floor is full" << index << RST << std::endl;
		return;
	}
	std::cout << R << "Character: Invalid inventory index " << index << RST << std::endl;
	return;
}

void Character::use(int index, ICharacter &target)
{
	if (index >= 0 && index < 4 && this->inventory[index])
	{
		this->inventory[index]->use(target);
		return ;
	}
	std::cout << R << "Character: Invalid inventory index " << index << " or no materia equipped" << RST << std::endl;
}