#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <ncurses.h>
#include <vector>
#include <iomanip>
#include <sstream>

class GameWidget {
public:
    GameWidget();
    ~GameWidget();

    void drawBoard(const std::vector<std::vector<int>>& board, int score);
    void showGameOver();

private:
    void initializeScreen();
    void drawBorders(int rows, int cols);
    void setColor(int value); // Set the color
};

#endif // GAMEWIDGET_H
