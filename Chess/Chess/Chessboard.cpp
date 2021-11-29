#include "Chessboard.h"


Chessboard::Chessboard(int size)
{
}

Chessboard::~Chessboard() {}

bool Chessboard::is_whites_turn() const { return false; }

bool Chessboard::is_game_over() const { return false; }

const Chessman* Chessboard::operator()(int row, int col) const {
  return nullptr;
}

bool Chessboard::can_pass_over(int row, int col) const { return false; }

bool Chessboard::can_land_on(int row, int col, bool is_white) const {
  return false;
}

bool Chessboard::can_capture_on(int row, int col, bool is_white) const {
  return false;
}

bool Chessboard::can_select_piece(int row, int col) const { return false; }

bool Chessboard::can_move_selection_to(int row, int col) const { return false; }

bool Chessboard::can_move(int from_row, int from_col, int to_row,
                          int to_col) const {
  return false;
}

void Chessboard::select_piece(int row, int col) {}

void Chessboard::move_selection_to(int row, int col) {}

void Chessboard::show() const {}
