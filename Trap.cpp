#include "Trap.h"

Trap::Trap(int x, int y) : Cell(x, y, 'T'), active(true) {}

bool Trap::isActive() {
    return active;
}

void Trap::apply(Cell& cell) {
    cell.setType('T');
    active = false;
}
