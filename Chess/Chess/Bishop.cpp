#include "Bishop.h"

Bishop::Bishop(bool is_white) {
  is_white ? this->color = WHITE : this->color = BLACK;
}
