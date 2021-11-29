#include "Chessman.h"

Chessman::Chessman(char symbol, bool is_white) {}

char Chessman::get_symbol() const { return 0; }

char Chessman::get_color() const { return 0; }

bool Chessman::is_white() const { return false; }

bool Chessman::can_move(int from_row, int from_col, int to_row, int to_col,
                        const Chessboard& cb) const {
  return false;
}
