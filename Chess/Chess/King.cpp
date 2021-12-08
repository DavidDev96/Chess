#include "King.h"

King::King(bool is_white) {
  if (is_white) {
    this->position.column = 3;
    this->position.row = 7;
  } else {
    this->position.column = 3;
    this->position.row = 0;
  }
  is_white ? this->color = WHITE : this->color = BLACK;
}

void King::get_info() const {
  cout << "KING"
       << " with position: (" << this->position.row << "|"
       << this->position.column << ")" << endl;
}

//bool King::can_move(int from_row, int from_col, int to_row, int to_col,
//                    const Chessboard& cb) const {
//  return false;
//}
