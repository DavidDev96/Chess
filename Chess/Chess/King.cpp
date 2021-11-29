#include "King.h"

King::King(char symbol, bool is_white) {
    this->position.x = 1;
    this->position.y = 1;
    this->color = color;
    this->isEssential = isEssential;

}

char King::get_symbol() const 
{ 
    return this->symbol; 
}

int King::get_color() const 
{ 
    return this->color; 
}

bool King::is_white() const 
{ 
    return this->color == 0 ? true : false; 
}

bool King::can_move(int from_row, int from_col, int to_row, int to_col,
                    const Chessboard& cb) const {
  return false;
}
