#include "Game.h"

int main() {
    
    Game game;

    
    game.initGame(2, 3, 5, 5);

    
    game.gameLoop(10, 2.0);

    return 0;
}
