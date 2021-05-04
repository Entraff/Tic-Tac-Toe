#include "type.h"

Move::Move(const int& row_, const int& column_) {
    this->row = row_;
    this->column = column_;
}

Move::Move() {
    this->row = 0;
    this->column = 0;
}

char cellToChar(const Cell& state) {
    switch(state) {
        case PLAYER_O:
            return 'O';
        case PLAYER_X:
            return 'X';
        case EMPTY:
            return '-';
        default:
            return ' ';
    }
}
