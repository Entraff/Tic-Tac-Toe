#include <iostream>
#include <vector>
#include "board.h"

int main() {
    Board board;

    Move move;
    
    std::cout << "To make a move, please enter the row and then column of your move." << std::endl;
    while (!board.checkWin()) {
        board.alternatePlayer();

        std::cout << "Player " << board.getPlayer() << " to move!" << std::endl;
        board.printBoard();
        
        while(true) {
            std::cin >> move.row >> move.column;

            if (board.isEmpty(move)) break;
            else std::cout << "That cell is already occupied! Please a different one!" << std::endl;
        }

        board.makeMove(move);
    }
    std::cout << "Player " << board.getPlayer() << " has won the game!" << std::endl;
    board.printBoard();
}
