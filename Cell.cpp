#include "Cell.h"

Cell::Cell(int x, int y, char type) : position(std::make_tuple(x, y)), type(type) {}

std::tuple<int, int> Cell::getPos() {
    return position;
}

char Cell::getType() {
    return type;
}

void Cell::setPos(int x, int y) {
    position = std::make_tuple(x, y);
}

void Cell::setType(char type) {
    this->type = type;
}
