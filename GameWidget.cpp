#include "GameWidget.h"

GameWidget::GameWidget() {
    initializeScreen();
}

GameWidget::~GameWidget() {
    endwin(); // Restore normal terminal behavior
}

void GameWidget::initializeScreen() {
    initscr();
    start_color();
    use_default_colors();

    // Define color pairs
    init_pair(1, COLOR_RED, -1);
    init_pair(2, COLOR_GREEN, -1);
    init_pair(3, COLOR_YELLOW, -1);
    init_pair(4, COLOR_BLUE, -1);
    init_pair(5, COLOR_MAGENTA, -1);
    init_pair(6, COLOR_CYAN, -1);
    init_pair(7, COLOR_WHITE, -1);

    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
}

void GameWidget::drawBoard(const std::vector<std::vector<int>>& board, int score) {
    clear();
    int size = board.size();

    // Display board 
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            int value = board[row][col];

            // Draw cell
            mvprintw(row * 3, col * 8, "+----+");
            mvprintw(row * 3 + 1, col * 8, "|");

            // color and display number
            if (value != 0) {
                setColor(value);
                mvprintw(row * 3 + 1, col * 8 + 2, "%4d", value);
                attroff(COLOR_PAIR(value % 7 + 1)); // Reset color
            }

            mvprintw(row * 3 + 2, col * 8, "+----+");
        }
    }

    // Display score
    mvprintw(size * 3, 0, "Score: %d", score);
    mvprintw(size * 3 + 1, 0, "Press 'u' to undo, 'q' to quit.");
    refresh();
}

void GameWidget::showGameOver() {
    mvprintw(0, 0, "Game Over! Press any key to exit...");
    getch();
}

void GameWidget::setColor(int value) {
    attron(COLOR_PAIR(value % 7 + 1));
}
