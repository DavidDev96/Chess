#pragma once
#include <vector>
#include <iostream>

#include "Bishop.h"
#include "Chessman.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
// custom chess figures
#include "Master.h"
#include "Archer.h"

class Chessboard {
 private:
  int size;
  Chessman* board[8][8] = {};
  int players_turn{WHITE};
  Pos selectedFigure; 

 public:
  explicit Chessboard(int size = 8);
  virtual ~Chessboard();
  void create_figures();
  bool is_whites_turn() const { return players_turn == WHITE; }
  bool is_game_over() const;
  const Chessman* operator()(int row, int col) const;
  bool can_pass_over(int row, int col) const;
  bool can_land_on(int row, int col, bool is_white) const;
  bool can_capture_on(int row, int col, bool is_white) const;
  bool can_select_piece(int row, int col) const { return board[row, col] != NULL; }
  bool can_move_selection_to(int row, int col) const;
  bool can_move(int from_row, int from_col, int to_row, int to_col) const;
  bool selected_piece_valid(int row, int col);
  void move_selection_to(int row, int col);
  int get_size() const { return size; }
  bool set_possible_positions(int row, int col) const;
  bool is_invalid_position(int position) const { return position < 0 || position >= size; }
  bool is_possible_position(int row, int col) const;
  bool is_free_position(int row, int col) const { return board[row][col] == NULL; }
  bool is_enemy_position(int color, int row, int col) const {
    if (this->board[row][col] != NULL) { return this->board[row][col]->get_color() != color;
    } else return false; 
  }
  bool is_ally_position(int color, int row, int col) const {
    if (this->board[row][col] != NULL) {
      return this->board[row][col]->get_color() == color;
    } else
      return false;
  }
  void show(bool figure_selected = false) const;
};
