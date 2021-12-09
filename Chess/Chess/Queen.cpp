#include "Queen.h"

Queen::Queen(bool is_white) {
  is_white ? this->color = WHITE : this->color = BLACK;
}