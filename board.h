#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "type.h"

class Board {
    private:
        char player;
        std::vector<std::vector<char>> board; 

        // CheckWin() is a wrapper for the 3 fucntions below
        bool checkHorizontal();
        bool checkVertical();
        bool checkDiagnol();
    public:
        Board();
        Board(const std::vector<std::vector<char>>&  board_);

        void printBoard();
        bool isEmpty(const Move& move);
        void alternatePlayer();
        char getPlayer();
        void makeMove(const Move& move);
        bool checkWin();
};

#endif
