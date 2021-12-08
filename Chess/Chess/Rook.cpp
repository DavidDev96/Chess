#include "Rook.h"

Rook::Rook(bool is_white) {
  if (is_white) {
    this->position.column = 0;
    this->position.row = 7;
  } else {
    this->position.column = 0;
    this->position.row = 0;
  }
  is_white ? this->color = WHITE : this->color = BLACK;
}

void Rook::get_info() const {
  cout << "ROOK"
       << " with position: (" << this->position.row << "|"
       << this->position.column << ")" << endl;
}