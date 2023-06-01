#ifndef GAME_H
#define GAME_H

#include "Cell.h"
#include "Character.h"
#include "Trap.h"
#include "Utils.h"
#include <vector>
#include <iostream>

class Game {
private:
    std::vector<Cell*> grid;

public:
    Game();
    std::vector<Cell*>& getGrid();
    void initGame(int numCharacters, int numTraps, int gridWidth, int gridHeight);
    void gameLoop(int maxIterations, double trapActivationDistance);
};

#endif  // GAME_H
