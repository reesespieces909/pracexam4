#include "Cell.h"
#include "Character.h"
#include "Trap.h"
#include <vector>

class Game {
public:
    Game();
    std::vector<Cell*>& getGrid();
    void initGame(int numCharacters, int numTraps, int gridWidth, int gridHeight);
    void gameLoop(int maxIterations, double trapActivationDistance);

private:
    std::vector<Cell*> grid;
    void moveCharacters();
    void checkTrapEffects(double trapActivationDistance);
    bool checkWinCondition();
    void printWinMessage(const Character& character);
};
