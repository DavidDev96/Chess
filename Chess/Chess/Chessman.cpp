#include "Chessman.h"

Chessman::Chessman(char symbol, bool is_white) {
  this->symbol = symbol;
  is_white ? this->color = WHITE : this->color = BLACK;
}

void Chessman::get_info() const {
  switch (this->symbol) {
    case K:
      cout << "KING";
      break;
    case Q:
      cout << "QUEEN";
      break;
    case B:
      cout << "BISHOP";
      break;
    case R:
      cout << "ROOK";
      break;
    case N:
      cout << "KNIGHT";
      break;
    case P:
      cout << "PAWN";
      break;
    default:
      break;
  }
  cout << " with position: (" << this->position.row << "|" << this->position.column << ")" << endl;
}

void Chessman::kill() {
    hasFallen = true;
}
