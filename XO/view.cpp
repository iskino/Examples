#include <iostream>
#include <cstdlib>
#include "view.h"

using std::cout;
using std::cin;
using std::endl;

GameView::GameView() {
    model = new GameModel();
}

GameView::~GameView() {
    delete model;
}

void GameView::show() const {
    cout << "---------------------------GAME X or O-------------------------\n\n\n\n";

    for (int i(0), k(1); i < 3; i++) {
        cout << "\n\t\t";
        cout << ' ' << (k) << " | " << (k + 1) << " | " << (k + 2);
        cout << "\t\t";
        cout << ' ' << print_XO(k) << " | " << print_XO(k + 1) << " | " << print_XO(k + 2);
        
        k +=3;
    }    

    cout << "\n\n\n\n\n---------------------------------------------------------------";
    return;
}

char GameView::print_XO(int i) const {
    if (model->getCell(i) == model->get_NO_CELL()) {
        return '-';
    } else if (model->getCell(i) == model->get_X_CELL()) {
        return 'X';
    } else if (model->getCell(i) == model->get_O_CELL()) {
        return 'O';
    }
}

void GameView::startGame() const {
    show();

    int cell_;
    int xo_;

    while (model->isWin() == model->get_PLAY_ON()) {
        cout << "\nVvedi kletky: ";
        cin >> cell_;
        cout << "\nVvedi X(1) ili O(2)..";
        cin >> xo_;
        if (model->getCell(cell_) == model->get_NO_CELL()) {
            model->getMove(cell_, xo_);
            system("clear");
            show();
        } else {
            cout << "\n\nZanyato!";
        }
    }

    if (model->isWin() == model->get_X_WIN()) {
        cout << "\n\nViigral krestik - X..";
    } else if (model->isWin() == model->get_O_WIN()) {
        cout << "\n\nViigral nolik - O..";
    } else if (model->isWin() == model->get_NO_WIN()) {
        cout << "\n\nNichya..";
    }
}
