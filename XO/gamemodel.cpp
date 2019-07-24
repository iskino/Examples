#include "gamemodel.h"

GameModel::GameModel() {
    for (int i(0); i < 3; i++) {
        for (int j(0); j < 3; j++) {
            cell[i][j] = NO_CELL;
        }
    }
}

void GameModel::getMove(int CELL_, int XO_) {
    *(((int*)cell) + (CELL_ - 1)) = XO_;
}

int GameModel::isWin() const {
    for (int i(0); i < 3; i++) {
        if ((cell[i][i] == cell[i][1]) && (cell[i][1] == cell[i][2]) && (cell[i][i] != NO_CELL)) {
            return (cell[i][i] == X_CELL) ? X_WIN : O_WIN;
        }
    }

    for (int i(0); i < 3; i++) {
        if ((cell[0][i] == cell[1][i]) && (cell[1][i] == cell[2][i]) && (cell[i][i] != NO_CELL)) {
            return (cell[i][i] == X_CELL) ? X_WIN : O_WIN;
        }
    }

    if ((cell[0][0] == cell[1][1]) && (cell[1][1] == cell[2][2]) && (cell[1][1] != NO_CELL)) {
            return (cell[1][1] == X_CELL) ? X_WIN : O_WIN;
    }

    if ((cell[0][2] == cell[1][1]) && (cell[1][1] == cell[2][0]) && (cell[1][1] != NO_CELL)) {
            return (cell[1][1] == X_CELL) ? X_WIN : O_WIN;
    }

    for (int i(0); i < 3; i++) {
        for (int j(0); j < 3; j++) {
            if (cell[i][j] == NO_CELL) {
                return PLAY_ON;
            }
        }
    }

    return NO_WIN;
}

int GameModel::getCell(int x) const {
    if (x >= 1 && x <= 3) {
        return cell[0][x-1];
    }
    if (x >= 4 && x <= 6) {
        return cell[1][x-4];
    }
    if (x >= 7 && x <= 9) {
        return cell[2][x-7];
    }
}

int  GameModel::get_NO_CELL() const {
    return NO_CELL;
}

int  GameModel::get_X_CELL() const {
    return X_CELL;
}

int  GameModel::get_O_CELL() const {
    return O_CELL;
}

int  GameModel::get_NO_WIN() const {
    return NO_WIN;
}

int  GameModel::get_PLAY_ON() const {
    return PLAY_ON;
}

int  GameModel::get_X_WIN() const {
    return X_WIN;
}

int  GameModel::get_O_WIN() const {
    return O_WIN;
}
























