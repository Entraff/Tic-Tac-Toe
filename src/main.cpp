#include <iostream>
#include <vector>
#include "board.h"

int main() {
    Board board;
    BoardState currentState;
    Move move;
    
    std::cout << "To make a move, please enter the row and then column of your move." << std::endl;
    while (true) {
        currentState = board.getState();
        // End the game loop if an ending position is found
        if (currentState != PLAYING) break;

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

    switch (currentState) {
        case WIN:
            std::cout << "Player " << board.getPlayer() << " has won the game!" << std::endl;
            break;
        case DRAW:
            std::cout << "Draw! No one has won the game." << std::endl;
            break;
    }

    board.printBoard();
}
