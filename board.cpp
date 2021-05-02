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

bool Board::checkDraw() {
    int row, column;
    for (row = 0; row < 3; ++row) {
        for (column = 0; column < 3; ++column) {
            if (board[row][column] == EMPTY) return false;
        }
    }
    return true;
}

bool Board::checkHorizontal() {
    int row, column;
    bool rowIsWinning;
    Cell comparator, currentCell;
    // Iterates through the rows
    for (row = 0; row < 3; ++row) {
        rowIsWinning = true;
        comparator = board[row][0];
        // If the first element of the row is empty, the entire row
        // is not winning, and will go onto the next row
        if (comparator == EMPTY) continue;

        // Iterates through columns
        for (column = 1; column < 3; ++column) {
            currentCell = board[row][column];
            // If the cell is empty or isn't the same as the first cell of the row
            // that row is not winning and will stop iterating through the row
            if (currentCell == EMPTY || currentCell != comparator) {
                rowIsWinning = false;
                break;
            } 
        }
        if (rowIsWinning) return true;
    }
    return false;
} 

bool Board::checkVertical() {
    int row, column;
    bool columnIsWinning;
    Cell comparator, currentCell;
    // Iterates through the columns 
    for (column = 0; column < 3; ++column) {
        columnIsWinning = true;
        comparator = board[0][column];
        // If the first element of the column is empty, the entire row
        // is not winning, and will go onto the next column 
        if (comparator == EMPTY) continue;

        // Iterates through rows 
        for (row = 1; row < 3; ++row) {
            currentCell = board[row][column];
            // If the cell is empty or isn't the same as the first cell of the column 
            // that row is not winning and will stop iterating through the column 
            if (currentCell == EMPTY || currentCell != comparator) {
                columnIsWinning = false;
                break;
            } 
        }
        if (columnIsWinning) return true;
    }
    return false;
}

bool Board::checkDiagnol() {
    const Cell LTRComparator = board[0][0];
    const Cell RTLComparator = board[0][board.size() - 1];
    Cell LTRCell, RTLCell;
    bool LTRWinning = true;
    bool RTLWinning = true;

    int RTLPtr = board.size() - 2;
    
    for (int row = 1; row < board.size(); ++row) {
        LTRCell = board[row][row];
        RTLCell = board[row][RTLPtr--];
        if (LTRCell == EMPTY || LTRCell != LTRComparator)
            LTRWinning = false;
        if (RTLCell == EMPTY || RTLCell != RTLComparator)
            RTLWinning = false;
    }
    return LTRWinning || RTLWinning;
}

bool Board::checkWin() {
    return checkHorizontal() || checkDiagnol() || checkVertical();
}

void Board::makeMove(const Move& move) {
    board[move.row][move.column] = player;    
}
