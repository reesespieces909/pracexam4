#include "Character.h"

Character::Character(int x, int y) : Cell(x, y, 'C') {}

void Character::move(int dx, int dy) {
    int currentX = std::get<0>(getPos());
    int currentY = std::get<1>(getPos());
    int newX = currentX + dx;
    int newY = currentY + dy;
    setPos(newX, newY);
}
