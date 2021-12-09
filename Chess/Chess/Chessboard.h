#pragma once
#include <iostream>
#include <vector>
#include <malloc.h>
// standard chess figures
#include "Bishop.h"
#include "Chessman.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
// custom chess figures
#include "Archer.h"
#include "Master.h"

struct Pos {
  int row{0};
  int column{0};
};

class Chessboard {
 private:
  int size;
  int players_turn{WHITE};
  bool game_over{false};

  Chessman* board[8][8] = {};
  Pos selectedFigure;

 public:
  explicit Chessboard(int size = 8);
  virtual ~Chessboard();
  const Chessman* operator()(int row, int col) const;

  void create_figures();

  int get_size() const { return size; }
  bool get_game_over() const { return game_over; }

  bool is_whites_turn() const { return players_turn == WHITE; }
  void check_game_over();

  bool can_select_piece(int row, int col) const { return board[row, col] != NULL; }
  bool can_move_selection_to(int row, int col) const;
  bool selected_piece_valid(int row, int col);
  void move_selection_to(int row, int col);

  bool set_possible_positions(int row, int col) const;
  bool is_invalid_position(int position) const { return position < 0 || position >= size; }
  bool is_possible_position(int row, int col) const;
  bool is_free_position(int row, int col) const { return board[row][col] == NULL; }

  bool is_enemy_position(int color, int row, int col) const {
    if (this->board[row][col] != NULL) {
      return this->board[row][col]->get_color() != color;
    } else
      return false;
  }
  bool is_ally_position(int color, int row, int col) const {
    if (this->board[row][col] != NULL) {
      return this->board[row][col]->get_color() == color;
    } else
      return false;
  }
  void show(bool figure_selected = false) const;
};
