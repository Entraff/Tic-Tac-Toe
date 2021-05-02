#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "type.h"

class Board {
    private:
        Cell player;
        std::vector<std::vector<Cell>> board; 

        void printRow(const std::vector<Cell>& row);
        // CheckWin() is a wrapper for the 3 fucntions below
        bool checkHorizontal();
        bool checkVertical();
        bool checkDiagnol();
    public:
        Board();
        Board(const std::vector<std::vector<Cell>>&  board_);

        void printBoard();
        bool isEmpty(const Move& move);
        bool checkDraw();
        void alternatePlayer();
        char getPlayer();
        void makeMove(const Move& move);
        bool checkWin();
};

#endif
