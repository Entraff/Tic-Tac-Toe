#ifndef BOARD_H
#define BOARD_H

#include <vector>

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
        Board(const std::vector<std::vector<char>>&  _board);
        void printBoard();
        bool isEmpty(const int& row, const int& column);
        void alternatePlayer();
        char getPlayer();
        void makeMove(const int& row, const int& column);
        bool checkWin();
};

#endif
