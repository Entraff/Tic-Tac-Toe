#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "type.h"

enum BoardState {
    DRAW, WIN, PLAYING
};

class Board {
    private:
        Cell player;
        std::vector<std::vector<Cell>> board; 

        void printRow(const std::vector<Cell>& row);
        bool checkDraw();
        bool checkWin();
        // CheckWin() is a wrapper for the 3 fucntions below
        bool checkHorizontal();
        bool checkVertical();
        bool checkDiagnol();
    public:
        Board();
        Board(const std::vector<std::vector<Cell>>&  board_);
        Board(const int& sideLength);

        void printBoard();
        bool isEmpty(const Move& move);
        void alternatePlayer();
        char getPlayer();
        void makeMove(const Move& move);
        BoardState getState();
};

#endif
