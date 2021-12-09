#include "Knight.h"

Knight::Knight(bool is_white) {
  is_white ? this->color = WHITE : this->color = BLACK;
}