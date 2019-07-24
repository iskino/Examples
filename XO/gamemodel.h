#ifndef GAMEMODEL_H
#define GAMEMODEL_H

class GameModel {
private:
    int cell[3][3];
    enum {NO_CELL, X_CELL, O_CELL};
    enum {NO_WIN, PLAY_ON, X_WIN, O_WIN};
public:
    GameModel();
    void getMove(int CELL_, int XO_);
    int isWin() const;
    int getCell(int x) const;
    int get_NO_CELL() const;
    int get_X_CELL() const;
    int get_O_CELL() const;
    int get_NO_WIN() const;
    int get_PLAY_ON() const;
    int get_X_WIN() const;
    int get_O_WIN() const;
};

#endif // GAMEMODEL_H
