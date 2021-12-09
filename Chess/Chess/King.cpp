#include "King.h"

King::King(bool is_white) {
  is_white ? this->color = WHITE : this->color = BLACK;
}
