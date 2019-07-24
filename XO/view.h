#ifndef VIEW_H
#define VIEW_H
#include "gamemodel.h"

class GameView {
private:
    GameModel *model;
    void show() const;
    char print_XO(int i) const;
public:
    GameView();
    ~GameView();
    void startGame() const;
};

#endif // VIEW_H
