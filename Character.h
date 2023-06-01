#ifndef CHARACTER_H
#define CHARACTER_H

#include "Cell.h"

class Character : public Cell {
public:
    Character(int x, int y) : Cell(x, y, 'C') {}

    void move(int dx, int dy) {
        int currentX = std::get<0>(getPos());
        int currentY = std::get<1>(getPos());
        int newX = currentX + dx;
        int newY = currentY + dy;
        setPos(newX, newY);
    }
};

#endif  // CHARACTER_H
