#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <vector>
#include <stack>
#include <random>
#include <ctime>
#include <algorithm>

using Board = std::vector<std::vector<int>>;

class GameModel {
public:
    GameModel(int size);

    bool moveUp();
    bool moveDown();
    bool moveLeft();
    bool moveRight();
    void undo(); // Undo the last move

    bool isGameOver() const;
    // const std::vector<std::vector<int>>& getBoard() const;
    const Board& getBoard() const;
    
    int getScore() const;

private:
    int size;
    int score;
    // std::vector<std::vector<int>> board;
    Board board;
    // std::stack<std::vector<std::vector<int>>> boardHistory; // for board states
    std::stack<Board> boardHistory; // for board states
    std::stack<int> scoreHistory; //  score history

    void saveState(); // saves the current state before making a move
    void addRandomTile();
    bool slideAndMerge(std::vector<int>& row);
    bool canMove() const;
    bool canMerge() const;
};

#endif // GAMEMODEL_H
