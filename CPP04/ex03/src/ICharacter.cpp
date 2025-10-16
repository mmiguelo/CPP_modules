#include "ICharacter.hpp"

void ICharacter::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        inventory[idx] = nullptr;  // Forget the pointer, don't delete it
}