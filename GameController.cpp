#include "GameController.h"

GameController::GameController(GameModel& model, GameWidget& widget)
    : model(model), widget(widget) {}

void GameController::run() {
    widget.drawBoard(model.getBoard(), model.getScore());

    while (!model.isGameOver()) {
        int ch = getch();
        bool moved = false;

        switch (ch) {
        case KEY_UP:
            moved = model.moveUp();
            break;
        case KEY_DOWN:
            moved = model.moveDown();
            break;
        case KEY_LEFT:
            moved = model.moveLeft();
            break;
        case KEY_RIGHT:
            moved = model.moveRight();
            break;
        case 'u': // Undo
            model.undo();
            moved = true;
            break;
        case 'q':
            return; // Quit
        }

        if (moved) {
            widget.drawBoard(model.getBoard(), model.getScore());
        }
    }

    widget.showGameOver();
}
