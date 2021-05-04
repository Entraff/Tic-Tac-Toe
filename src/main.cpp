#include <iostream>
#include <vector>
#include "board.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    int boardLength;
    cout << "Please enter how many units long you want the board to be" << endl;

    while (true) {
        cin >> boardLength;
        if (boardLength >= 2) break;
        else cout << "Please choose a length greater than or equal to 2" << endl;
    } 

    BoardState currentState;
    Move move;
    Board board(boardLength);

    cout << "To make a move, please enter the row and then column of your move." << endl;
    while (true) {
        currentState = board.getState();
        // End the game loop if an ending position is found
        if (currentState != PLAYING) break;

        board.alternatePlayer();
        std::cout << "Player " << board.getPlayer() << " to move!" << endl;
        board.printBoard();
        
        while(true) {
            cin >> move.row >> move.column;

            if (board.isEmpty(move)) break;
            else cout << "That cell is already occupied! Please a different one!" << endl;
        }

        board.makeMove(move);
    }

    switch (currentState) {
        case WIN:
            cout << "Player " << board.getPlayer() << " has won the game!" << endl;
            break;
        case DRAW:
            cout << "Draw! No one has won the game." << endl;
            break;
    }

    board.printBoard();
}
