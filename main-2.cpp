#include "Cell.h"
#include "Effect.h"
#include "Trap.h"
#include "Character.h"
#include "Utils.h"
#include <iostream>

int main() {
    // Create Trap object
    Trap trap(3, 4);
    std::cout << "Trap cuurently active: " << (trap.isActive() ? "true" : "false") << std::endl;

    // Create Character object
    Character character(5, 2);
    std::cout << "Character position: (" << std::get<0>(character.getPos()) << ", " << std::get<1>(character.getPos()) << ")" << std::endl;

    // Move character
    character.move(-1, 2);
    std::cout << "Characters new position: (" << std::get<0>(character.getPos()) << ", " << std::get<1>(character.getPos()) << ")" << std::endl;

    // Apply the trap effect 
    trap.apply(character);
    std::cout << "Character type after trap effect: " << character.getType() << std::endl;
    std::cout << "Trap active: " << (trap.isActive() ? "true" : "false") << std::endl;

    return 0;
}
