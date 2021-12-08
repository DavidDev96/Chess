#include "Archer.h"

Archer::Archer(bool is_white) {
  if (is_white) {
    this->position.column = 4;
    this->position.row = 4;
  } else {
    this->position.column = 4;
    this->position.row = 4;
  }
  is_white ? this->color = WHITE : this->color = BLACK;
}

void Archer::get_info() const {
  cout << "Archer"
       << " with position: (" << this->position.row << "|"
       << this->position.column << ")" << endl;
}
