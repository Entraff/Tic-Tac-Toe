#ifndef TYPE_H
#define TYPE_H

enum Cell {
    PLAYER_X,
    PLAYER_O,
    EMPTY
};

struct Move {
    int row;
    int column;
    Move(const int& row_, const int& column_);
    Move();
};

char cellToChar(const Cell& state); 

#endif // TYPE_H
