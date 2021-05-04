#include <vector>
#include <iostream>
#include "board.h"
#include "type.h"


Board::Board():
    player(PLAYER_X),
    board(std::vector<std::vector<Cell>>(3, 
          std::vector<Cell>(3, EMPTY)))
    {}

Board::Board(const std::vector<std::vector<Cell>>& board_):
    player(PLAYER_X),
    board(board_)
    {}

Board::Board(const int& sideLength):
    player(PLAYER_X),
    board(std::vector<std::vector<Cell>>(sideLength,
                      std::vector<Cell>(sideLength, EMPTY)))
    {}


void Board::alternatePlayer() {
    player = player == PLAYER_X ? PLAYER_O : PLAYER_X;
}

void Board::printRow(const std::vector<Cell>& row) {
    std::cout << ' ';
    for (int column = 0; column < 2; ++column) {
        std::cout << cellToChar(row[column]) << " | ";
    }
    std::cout << cellToChar(row[row.size() - 1]) << std::endl;
}

void Board::printBoard() {
    for (int row = 0; row < 2; ++row) {
        printRow(board[row]);
        std::cout << "---+---+---" << std::endl;
    }
    printRow(board[board.size() - 1]);
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
