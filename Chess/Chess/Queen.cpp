#include "Queen.h"

Queen::Queen(bool is_white) {
  if (is_white) {
    this->position.column = 4;
    this->position.row = 7;
  } else {
    this->position.column = 4;
    this->position.row = 0;
  }
  is_white ? this->color = WHITE : this->color = BLACK;
}

//bool Queen::can_move(int from_row, int from_col, int to_row, int to_col,
//                     const Chessboard& cb) const {
//  return false;
//}

void Queen::get_info() const {
  cout << "QUEEN"
       << " with position: (" << this->position.row << "|"
       << this->position.column << ")" << endl;
}