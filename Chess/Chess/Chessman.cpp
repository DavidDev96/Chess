#include "Chessman.h"

Chessman::Chessman(char symbol, bool is_white) {
  this->symbol = symbol;
  is_white ? this->color = WHITE : this->color = BLACK;
}

void Chessman::kill() {
    hasFallen = true;
}
