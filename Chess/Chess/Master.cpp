#include "Master.h"

Master::Master(bool is_white) {
  if (is_white) {
    this->position.column = 4;
    this->position.row = 4;
  } else {
    this->position.column = 3;
    this->position.row = 3;
  }
  is_white ? this->color = WHITE : this->color = BLACK;
}

void Master::get_info() const {
  cout << "Master"
       << " with position: (" << this->position.row << "|"
       << this->position.column << ")" << endl;
}
