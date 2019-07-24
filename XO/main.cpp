#include "gamemodel.h"
#include "view.h"

int main()
{
    GameView *game = new GameView();

    game->startGame();

    delete game;

    return 0;
}
