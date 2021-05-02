#include "type.h"

Move::Move(const int& row_, const int& column_):
    row(row_),
    column(column_)
    {}

Move::Move():
    row(0),
    column(0)
    {}

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
