#include "Archer.h"

Archer::Archer(bool is_white) {
  is_white ? this->color = WHITE : this->color = BLACK;
}
