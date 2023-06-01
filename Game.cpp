#include "Game.h"

Game::Game() {}

std::vector<Cell*>& Game::getGrid() {
    return grid;
}

void Game::initGame(int numCharacters, int numTraps, int gridWidth, int gridHeight) {
    // Create characters
    for (int i = 0; i < numCharacters; i++) {
        std::tuple<int, int> randomPos = Utils::generateRandomPos(gridWidth, gridHeight);
        Character* character = new Character(std::get<0>(randomPos), std::get<1>(randomPos));
        grid.push_back(character);
    }

    // Create traps
    for (int i = 0; i < numTraps; i++) {
        std::tuple<int, int> randomPos = Utils::generateRandomPos(gridWidth, gridHeight);
        Trap* trap = new Trap(std::get<0>(randomPos), std::get<1>(randomPos));
        grid.push_back(trap);
    }
}

void Game::gameLoop(int maxIterations, double trapActivationDistance) {
    for (int iteration = 0; iteration < maxIterations; iteration++) {
        // Move all characters to the right
        for (Cell* cell : grid) {
            Character* character = dynamic_cast<Character*>(cell);
            if (character != nullptr) {
                character->move(1, 0);
            }
        }

        // Check for nearby traps and apply required effect
        for (Cell* cell : grid) {
            Character* character = dynamic_cast<Character*>(cell);
            if (character != nullptr) {
                for (Cell* otherCell : grid) {
                    Trap* trap = dynamic_cast<Trap*>(otherCell);
                    if (trap != nullptr) {
                        std::tuple<int, int> pos1 = character->getPos();
                        std::tuple<int, int> pos2 = trap->getPos();
                        double distance = Utils::calculateDistance(pos1, pos2);
                        if (distance <= trapActivationDistance) {
                            trap->apply(*character);
                        }
                    }
                }
            }
        }

        // Iff character has stepped outside 
        for (Cell* cell : grid) {
            Character* character = dynamic_cast<Character*>(cell);
            if (character != nullptr) {
                std::tuple<int, int> pos = character->getPos();
                int x = std::get<0>(pos);
                int y = std::get<1>(pos);
                if (x < 0 || y < 0 || x >= 10 || y >= 10) {
                    std::cout << "Character has won the game!" << std::endl;
                    return;
                }
            }
        }
    }

    std::cout
