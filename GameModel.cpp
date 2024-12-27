#include "GameModel.h"

GameModel::GameModel(int size) : size(size), score(0), board(size, std::vector<int>(size, 0)) {
    addRandomTile();
    addRandomTile();
}

void GameModel::saveState() {
    boardHistory.push(board);
    scoreHistory.push(score);
}

void GameModel::undo() {
    if (!boardHistory.empty()) {
        board = boardHistory.top();
        boardHistory.pop();
        score = scoreHistory.top();
        scoreHistory.pop();
    }
}

bool GameModel::moveUp() {
    saveState();
    bool moved = false;

    for (int col = 0; col < size; ++col) {
        std::vector<int> column(size);

        for (int row = 0; row < size; ++row){
            column[row] = board[row][col];
        }

        if (slideAndMerge(column)) {
            moved = true;
            for (int row = 0; row < size; ++row){
                board[row][col] = column[row];
            }
        }
    }
    if (moved) addRandomTile();

    return moved;
}

bool GameModel::moveDown() {
    bool moved = false;
    for (int col = 0; col < size; ++col) {
        std::vector<int> column(size);
        for (int row = 0; row < size; ++row){
            column[row] = board[row][col];
        }

        std::reverse(column.begin(), column.end());
        if (slideAndMerge(column)) {
            moved = true;
            std::reverse(column.begin(), column.end());
            for (int row = 0; row < size; ++row){
                board[row][col] = column[row];
            }
        }
    }
    if (moved) addRandomTile();

    return moved;
}

bool GameModel::moveLeft() {
    bool moved = false;

    for (int row = 0; row < size; ++row) {
        if (slideAndMerge(board[row])) {
            moved = true;
        }
    }
    if (moved) addRandomTile();

    return moved;
}

bool GameModel::moveRight() {
    bool moved = false;

    for (int row = 0; row < size; ++row) {
        std::reverse(board[row].begin(), board[row].end());
        if (slideAndMerge(board[row])) {
            moved = true;
        }
        std::reverse(board[row].begin(), board[row].end());
    }
    if (moved) addRandomTile();

    return moved;
}

bool GameModel::slideAndMerge(std::vector<int>& row) {
    bool moved = false;
    int n = row.size();
    std::vector<int> newRow(n, 0);
    int pos = 0;

    for (int i = 0; i < n; ++i) {
        if (row[i] != 0) {
            if (pos > 0 && newRow[pos - 1] == row[i]) {
                newRow[pos - 1] *= 2;
                score += newRow[pos - 1];
                moved = true;
            } 
            else {
                newRow[pos++] = row[i];
            }
        }
    }

    if (row != newRow) {
        row = newRow;
        moved = true;
    }

    return moved;
}

bool GameModel::isGameOver() const {
    return !canMove() && !canMerge();
}

const std::vector<std::vector<int>>& GameModel::getBoard() const {
    return board;
}

int GameModel::getScore() const {
    return score;
}

void GameModel::addRandomTile() {
    std::vector<std::pair<int, int>> emptyCells;
    for (int row = 0; row < size; ++row){
        for (int col = 0; col < size; ++col){
            if (board[row][col] == 0){
                emptyCells.emplace_back(row, col);
            }
        }
    }

    if (!emptyCells.empty()) {
        std::mt19937 rng(std::time(nullptr));
        std::uniform_int_distribution<int> dist(0, emptyCells.size() - 1);
        auto [row, col] = emptyCells[dist(rng)];
        board[row][col] = (std::rand() % 10 < 9) ? 2 : 4;
    }
}

bool GameModel::canMove() const {
    for (int row = 0; row < size; ++row){
        for (int col = 0; col < size; ++col){
            if (board[row][col] == 0){
                return true;
            }
        }
    }

    return false;
}

bool GameModel::canMerge() const {
    for (int row = 0; row < size; ++row){
        for (int col = 0; col < size; ++col) {
            if (col + 1 < size && board[row][col] == board[row][col + 1]){
                return true;
            }
            if (row + 1 < size && board[row][col] == board[row + 1][col]){
                return true;
            }
        }
    }
    
    return false;
}
