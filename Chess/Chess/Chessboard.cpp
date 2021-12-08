#include "Chessboard.h"

vector<Pos> possiblePositions;

Chessboard::Chessboard(int size) { this->size = size; }

Chessboard::~Chessboard() { delete[] board; }

void Chessboard::create_figures() {
  // Black figures
  board[0][0] = new Rook(BLACK);
  board[0][1] = new Knight(BLACK);
  board[0][2] = new Bishop(BLACK);
  board[0][3] = new King(BLACK);
  board[0][4] = new Queen(BLACK);
  board[0][5] = new Bishop(BLACK);
  board[0][6] = new Knight(BLACK);
  board[0][7] = new Rook(BLACK);
  board[1][0] = new Pawn(BLACK);
  board[1][1] = new Pawn(BLACK);
  board[1][2] = new Pawn(BLACK);
  board[1][3] = new Pawn(BLACK);
  board[1][4] = new Pawn(BLACK);
  board[1][5] = new Pawn(BLACK);
  board[1][6] = new Pawn(BLACK);
  board[1][7] = new Pawn(BLACK);
  // White figures
  board[7][0] = new Rook(WHITE);
  board[7][1] = new Knight(WHITE);
  board[7][2] = new Bishop(WHITE);
  board[7][3] = new King(WHITE);
  board[7][4] = new Queen(WHITE);
  board[7][5] = new Bishop(WHITE);
  board[7][6] = new Knight(WHITE);
  board[7][7] = new Rook(WHITE);
  board[6][0] = new Pawn(WHITE);
  board[6][1] = new Pawn(WHITE);
  board[6][2] = new Pawn(WHITE);
  board[6][3] = new Pawn(WHITE);
  board[6][4] = new Pawn(WHITE);
  board[6][5] = new Pawn(WHITE);
  board[6][6] = new Pawn(WHITE);
  board[6][7] = new Pawn(WHITE);
}

bool Chessboard::is_game_over() const {
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      if (this->board[i][j] != NULL) {
        if ((this->board[i][j]->get_symbol() == K) &&
            this->board[i][j]->has_fallen()) {
          if (this->board[i][j]->get_color() == WHITE) {
            cout << "BLACK is the winner!" << endl;
          } else {
            cout << "WHITE is the winner!" << endl;
          }
          return true;
        }
      }
    }
  }
  return false;
}

const Chessman* Chessboard::operator()(int row, int col) const {
  if (this->board[row][col] != NULL) {
    return this->board[row][col];
  } else {
    return NULL;
  }
}

bool Chessboard::can_pass_over(int row, int col) const { return false; }

bool Chessboard::can_land_on(int row, int col, bool is_white) const {
  return false;
}

bool Chessboard::can_capture_on(int row, int col, bool is_white) const {
  return false;
}

bool Chessboard::can_move_selection_to(int row, int col) const { return true; }

bool Chessboard::can_move(int from_row, int from_col, int to_row,
                          int to_col) const {
  // position is outter matrix - return false
  if (is_invalid_position(from_row) || is_invalid_position(from_col) ||
      is_invalid_position(to_row) || is_invalid_position(to_col))
    return false;

  // no figure selected - return false
  if (is_free_position(from_row, to_col)) return false;

  // WHITE PAWN MOVE - can only move forward or kill diagonal
  // TODO Pawns can move 2 positions forward if in initial position

  // KING - can move all directions for one field
  if (this->board[from_row][from_col]->get_symbol() == K) {
    return ((to_row = from_row || to_row == from_row - 1 ||
                      to_row == from_row + 1) &&
            (to_col == from_col - 1 || to_col == from_col + 1 ||
             to_col == from_col)) &&
           (is_free_position(to_row, to_col) ||
            is_enemy_position(this->board[from_row][from_col]->get_color(),
                              to_row, to_col));
  }

  // BISHOP - can go diagonal until there is a figure
  if (this->board[from_row][from_col]->get_symbol() == B) {
    // TODO
  }

  // ROOK - can go vertically or horizontally until there is a figure
  if (this->board[from_row][from_col]->get_symbol() == R) {
    if (from_row != to_row && from_col != to_col) return false;
    if (from_row == to_row) {
      for (size_t i = from_col; i < to_col; i++) {
        if (!is_free_position(i, from_col)) return false;
      }
    } else if (from_col == to_col) {
      for (size_t i = from_row; i < to_row; i++) {
        if (!is_free_position(from_col, i)) return false;
      }
    }
    // destination position valid
    if (is_free_position(to_row, to_col) ||
        is_enemy_position(this->board[from_col][from_row]->get_color(), to_row,
                          to_col))
      return true;
  }

  // QUEEN - can move in all directions as far as possible
  if (this->board[from_row][from_col]->get_symbol() == Q) {
    // go upwards
    if (from_col == to_col && from_row > to_row) {
      for (size_t i = to_row; i < from_row; i++) {
        if (!is_free_position(i, from_col)) return false;
      }
    }
    // go downwards
    if (from_col == to_col && from_row < to_row) {
      for (size_t i = to_row; i < from_row; i++) {
        if (!is_free_position(i, from_col)) return false;
      }
    }
    // go right
    if (from_col < to_col && from_row == to_row) {
      for (size_t i = to_row; i < from_row; i++) {
        if (!is_free_position(i, from_col)) return false;
      }
    }
    // go left
    if (from_col == to_col && from_row > to_row) {
      for (size_t i = to_row; i < from_row; i++) {
        if (!is_free_position(i, from_col)) return false;
      }
    }

    // destination position valid
    if (is_free_position(to_row, to_col) ||
        is_enemy_position(this->board[from_col][from_row]->get_color(), to_row,
                          to_col))
      return true;
  }
}

void Chessboard::select_piece(int row, int col) {
  this->board[row][col]->get_info();
  this->selectedFigure = {row,col};
  set_possible_positions(row, col);
  show(true);
  players_turn == WHITE ? players_turn = BLACK : players_turn = WHITE;
}

void Chessboard::move_selection_to(int row, int col) 
{
    if (is_enemy_position(players_turn, row, col)) {
        // Killed an enemy
        board[row][col] = NULL;
    }
    board[row][col] = board[selectedFigure.row][selectedFigure.column];
    board[selectedFigure.row][selectedFigure.column] = NULL;
    cout << "Figure moved to (" << row << "|" << col << ")" << endl;
}

void Chessboard::set_possible_positions(int row, int col) const {
  switch (this->board[row][col]->get_symbol()) {
    case P:
      // White Pawn
      if (this->board[row][col]->is_white()) {
        possiblePositions.push_back({row - 1, col});
        if (is_enemy_position(WHITE, row - 1, col - 1)) {
          possiblePositions.push_back({row - 1, col - 1});
        }
        if (is_enemy_position(WHITE, row - 1, col + 1)) {
          possiblePositions.push_back({row - 1, col + 1});
        }
        // Black Pawn
      } else {
        possiblePositions.push_back({row + 1, col});
        if (is_enemy_position(WHITE, row + 1, col - 1)) {
          possiblePositions.push_back({row + 1, col - 1});
        }
        if (is_enemy_position(WHITE, row + 1, col + 1)) {
          possiblePositions.push_back({row + 1, col + 1});
        }
      }
      break;
    case K:
        break;
    default:
      break;
  }
}

bool Chessboard::is_possible_position(int row, int col) const {
  Pos currentPosition = {row, col};
  bool positionFound = false;

  std::vector<Pos>::iterator it = std::find_if(
      begin(possiblePositions), end(possiblePositions),
                         [&](const Pos& p) {
                           if (p.row == currentPosition.row && p.column == currentPosition.column) 
                           { 
                               positionFound = true;
                               return true;
                           }
                         });
  return positionFound;
}

void Chessboard::show(bool figure_selected) const {
  for (int i = -1; i < this->size; i++) {
    for (int j = -1; j < this->size; j++) {
      // show columns
      if (i == -1 && j == -1) {
        printf("%3c", ' ');
      } else if (j == -1) {
        printf("%3d", i);
      }
      // show rows
      else if (i == -1) {
        printf("%3d", j);
      } else {
        if (figure_selected) {
          // possible positions are showed with brackets
          if (is_possible_position(i, j)) {
            if (this->board[i][j] != NULL) {
              if (this->board[i][j]->get_color() == 0) {
                cout << '[' << tolower(this->board[i][j]->get_symbol()) << ']';
              } else {
                cout << '[' + this->board[i][j]->get_symbol() + ']';
              }
            } else {
              cout << "[.]";
            }
          } else {
            if (this->board[i][j] != NULL) {
              if (this->board[i][j]->get_color() == 0) {
                // black figure's symbol will be shown as lower case
                printf("%3c", tolower(this->board[i][j]->get_symbol()));
              } else {
                printf("%3c", this->board[i][j]->get_symbol());
              }
            } else {
              printf("%3c", '.');
            }
          }
        } else {
          if (this->board[i][j] != NULL) {
            if (this->board[i][j]->get_color() == 0) {
              // black figure's symbol will be shown as lower case
              printf("%3c", tolower(this->board[i][j]->get_symbol()));
            } else {
              printf("%3c", this->board[i][j]->get_symbol());
            }
          } else {
            printf("%3c", '.');
          }
        }
      }
    }
    printf("\n");
  }
}
