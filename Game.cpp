#include "Game.h"
#include "Utils.h"
#include <iostream>

Game::Game() {}

std::vector<Cell*>& Game::getGrid() {
    return grid;
}

void Game::initGame(int numCharacters, int numTraps, int gridWidth, int gridHeight) {
    
    for (Cell* cell : grid) {
        delete cell;
    }
    grid.clear();

  
    for (int i = 0; i < numCharacters; i++) {
        std::tuple<int, int> pos = Utils::generateRandomPos(gridWidth, gridHeight);
        grid.push_back(new Character(std::get<0>(pos), std::get<1>(pos)));
    }

    
    for (int i = 0; i < numTraps; i++) {
        std::tuple<int, int> pos = Utils::generateRandomPos(gridWidth, gridHeight);
        grid.push_back(new Trap(std::get<0>(pos), std::get<1>(pos)));
    }
}

void Game::gameLoop(int maxIterations, double trapActivationDistance) {
    for (int iteration = 0; iteration < maxIterations; iteration++) {
        moveCharacters();
        checkTrapEffects(trapActivationDistance);

        if (checkWinCondition()) {
            break;
        }
    }

    std::cout << "Maximum number of iterations reached. Game over.\n";
}

void Game::moveCharacters() {
    for (Cell* cell : grid) {
        Character* character = dynamic_cast<Character*>(cell);
        if (character != nullptr) {
            character->move(1, 0);
        }
    }
}

void Game::checkTrapEffects(double trapActivationDistance) {
    for (Cell* cell : grid) {
        Character* character = dynamic_cast<Character*>(cell);
        if (character != nullptr) {
            for (Cell* otherCell : grid) {
                Trap* trap = dynamic_cast<Trap*>(otherCell);
                if (trap != nullptr && trap->isActive()) {
                    double distance = Utils::calculateDistance(character->getPos(), trap->getPos());
                    if (distance <= trapActivationDistance) {
                        trap->apply(*character);
                    }
                }
            }
        }
    }
}

bool Game::checkWinCondition() {
    for (Cell* cell : grid) {
        Character* character = dynamic_cast<Character*>(cell);
        if (character != nullptr) {
            std::tuple<int, int> pos = character->getPos();
            if (std::get<0>(pos) < 0 || std::get<1>(pos) < 0) {
                printWinMessage(*character);
                return true;
            }
        }
    }
    return false;
}

void Game::printWinMessage(const Character& character) {
    std::cout << "Character has won the game!\n";
}

