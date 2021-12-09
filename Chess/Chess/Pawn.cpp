#include "Pawn.h"

Pawn::Pawn(bool is_white) {
  is_white ? this->color = WHITE : this->color = BLACK;
}