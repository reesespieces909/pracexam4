#include "Game.h"

int main() {
    Game game;
    game.initGame(3, 5, 10, 10);
    game.gameLoop(100, 3.0);

    return 0;
}
