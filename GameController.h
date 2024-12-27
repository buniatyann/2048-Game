#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "GameModel.h"
#include "GameWidget.h"

class GameController {
public:
    GameController(GameModel& model, GameWidget& widget);
    void run();

private:
    GameModel& model;
    GameWidget& widget;
};

#endif // GAMECONTROLLER_H
