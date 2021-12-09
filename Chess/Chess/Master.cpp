#include "Master.h"

Master::Master(bool is_white) {
  is_white ? this->color = WHITE : this->color = BLACK;
}