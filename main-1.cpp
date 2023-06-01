#include "Cell.h"
#include "Effect.h"
#include "Utils.h"
#include <iostream>

int main() {
    
    Cell cell(3, 4, 'A');
    std::cout << "Pos: (" << std::get<0>(cell.getPos()) << ", " << std::get<1>(cell.getPos()) << ")" << std::endl;
    std::cout << "Type: " << cell.getType() << std::endl;

    cell.setPos(5, 2);
    cell.setType('B');
    std::cout << "New pos: (" << std::get<0>(cell.getPos()) << ", " << std::get<1>(cell.getPos()) << ")" << std::endl;
    std::cout << "New type: " << cell.getType() << std::endl;

    
   
