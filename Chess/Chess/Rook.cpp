#include "Rook.h"

Rook::Rook(bool is_white) {
  is_white ? this->color = WHITE : this->color = BLACK;
}