#include <vector>
#include <iostream>
#include "board.h"
#include "type.h"

using std::vector;

// TODO Make a "isValidMove" function to filter user input

Board::Board(const int& sideLength_) {
    this->player = PLAYER_X;
    this->sideLength = sideLength_;
    this->board = vector<vector<Cell>>(sideLength_,
                         vector<Cell>(sideLength_, EMPTY));
}

void Board::printRow(const std::vector<Cell>& row) {
    int finalElement = sideLength - 1;
    std::cout << ' ';
    for (int column = 0; column < finalElement; ++column) {
        std::cout << cellToChar(row[column]) << " | ";
    }
    std::cout << cellToChar(row[finalElement]) << std::endl;
}

void Board::printBoard() {
    int finalElement = sideLength - 1;
    int row, separator;
    for (row = 0; row < finalElement; ++row) {
        printRow(board[row]);
        for (separator = 0; separator < finalElement; ++separator) {
            std::cout << "---+";
        } 
        std::cout << "---" << std::endl;
    }
    printRow(board[finalElement]);
}


void Board::alternatePlayer() {
    player = player == PLAYER_X ? PLAYER_O : PLAYER_X;
}

char Board::getPlayer() {
    return cellToChar(player);
}

bool Board::isEmpty(const Move& move) {
    return board[move.row][move.column] == EMPTY;
}

void Board::makeMove(const Move& move) {
    board[move.row][move.column] = player;    
}
