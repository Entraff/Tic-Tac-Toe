#include <vector>
#include <iostream>
#include "board.h"
#include "type.h"

Board::Board():
    player('X'),
    board(std::vector<std::vector<char>>(3, 
          std::vector<char>(3, '-')))
    {}

Board::Board(const std::vector<std::vector<char>>& board_):
    player('X'),
    board(board_)
    {}

void Board::alternatePlayer() {
    player = player == 'X' ? 'O' : 'X';
}

void Board::printBoard() {
    std::cout << ' ' << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << std::endl;
    std::cout << "---" << "+" << "---" << "+" << "---" << std::endl;
    std::cout << ' ' << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << std::endl;
    std::cout << "---" << "+" << "---" << "+" << "---" << std::endl;
    std::cout << ' ' << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << std::endl;
}

char Board::getPlayer() {
    return player;
}

bool Board::isEmpty(const int& row, const int& column) {
    return board[row][column] == '-';
}

bool Board::checkHorizontal() {
    int row, column;
    bool rowIsWinning;
    char comparator, currentCell;
    // Iterates through the rows
    for (row = 0; row < 3; ++row) {
        rowIsWinning = true;
        comparator = board[row][0];
        // If the first element of the row is empty, the entire row
        // is not winning, and will go onto the next row
        if (comparator == '-') continue;

        // Iterates through columns
        for (column = 1; column < 3; ++column) {
            currentCell = board[row][column];
            // If the cell is empty or isn't the same as the first cell of the row
            // that row is not winning and will stop iterating through the row
            if (currentCell == '-' || currentCell != comparator) {
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
    char comparator, currentCell;
    // Iterates through the columns 
    for (column = 0; column < 3; ++column) {
        columnIsWinning = true;
        comparator = board[0][column];
        // If the first element of the column is empty, the entire row
        // is not winning, and will go onto the next column 
        if (comparator == '-') continue;

        // Iterates through rows 
        for (row = 1; row < 3; ++row) {
            currentCell = board[row][column];
            // If the cell is empty or isn't the same as the first cell of the column 
            // that row is not winning and will stop iterating through the column 
            if (currentCell == '-' || currentCell != comparator) {
                columnIsWinning = false;
                break;
            } 
        }
        if (columnIsWinning) return true;
    }
    return false;
}

bool Board::checkDiagnol() {
    const char LTRComparator = board[0][0];
    const char RTLComparator = board[0][board.size() - 1];
    char LTRCell, RTLCell;
    bool LTRWinning = true;
    bool RTLWinning = true;

    int RTLPtr = board.size() - 2;
    
    for (int row = 1; row < board.size(); ++row) {
        LTRCell = board[row][row];
        RTLCell = board[row][RTLPtr--];
        if (LTRCell == '-' || LTRCell != LTRComparator)
            LTRWinning = false;
        if (RTLCell == '-' || RTLCell != RTLComparator)
            RTLWinning = false;
    }
    return LTRWinning || RTLWinning;
}

bool Board::checkWin() {
    return checkHorizontal() || checkDiagnol() || checkVertical();
}

void Board::makeMove(const int& row, const int& column) {
    board[row][column] = player;    
}
