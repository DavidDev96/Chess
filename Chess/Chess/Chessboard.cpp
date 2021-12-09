#include "Chessboard.h"

vector<Pos> possiblePositions;

Chessboard::Chessboard(int size) {
  this->size = size;
  // TODO resize board if not default size
}

Chessboard::~Chessboard() {}

void Chessboard::create_figures() {
  // Initializing the figures on the board. Will have a fixed position

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
  int lastRow = get_size()-1;
  board[lastRow][0] = new Rook(WHITE);
  board[lastRow][1] = new Knight(WHITE);
  board[lastRow][2] = new Bishop(WHITE);
  board[lastRow][3] = new King(WHITE);
  board[lastRow][4] = new Queen(WHITE);
  board[lastRow][5] = new Bishop(WHITE);
  board[lastRow][6] = new Knight(WHITE);
  board[lastRow][7] = new Rook(WHITE);
  board[lastRow - 1][0] = new Pawn(WHITE);
  board[lastRow - 1][1] = new Pawn(WHITE);
  board[lastRow - 1][2] = new Pawn(WHITE);
  board[lastRow - 1][3] = new Pawn(WHITE);
  board[lastRow - 1][4] = new Pawn(WHITE);
  board[lastRow - 1][5] = new Pawn(WHITE);
  board[lastRow - 1][6] = new Pawn(WHITE);
  board[lastRow - 1][7] = new Pawn(WHITE);

  // For test purposes
  // board[3][3] = new Bishop(WHITE);
  // board[2][3] = new Master(WHITE);
  // board[2][4] = new Knight(WHITE);
  board[4][4] = new King(WHITE);
}

void Chessboard::check_game_over() {
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      if (this->board[i][j] != NULL) {
        /* iterating over all figures and checking if essential figures have
           fallen */
        if ((this->board[i][j]->is_essential()) &&
            this->board[i][j]->has_fallen()) {
          if (this->board[i][j]->get_color() == WHITE) {
            cout << endl;
            cout << "BLACK is the winner!" << endl;
            game_over = true;
          } else {
            cout << endl;
            cout << "WHITE is the winner!" << endl;
            game_over = true;
          }
        }
      }
    }
  }
}

const Chessman* Chessboard::operator()(int row, int col) const {
  // Giving information of selected figure
  if (this->board[row][col] != NULL) {
    cout << this->board[row][col]->get_symbol() << " selected with color "
         << (this->board[row][col]->is_white() ? "WHITE" : "BLACK") << endl;
    return this->board[row][col];
  } else {
    return NULL;
  }
}

bool Chessboard::selected_piece_valid(int row, int col) {
  this->selectedFigure = {row, col};
  if (!set_possible_positions(row, col)) {
    return false;
  }
  return true;
}

bool Chessboard::set_possible_positions(int row, int col) const {
  int tempCol = col;
  switch (board[row][col]->get_symbol()) {
    case P:
      // BLACK Pawn
      if (board[row][col]->is_white()) {
        possiblePositions.push_back({row + 1, col});
        if (is_enemy_position(players_turn, row + 1, col - 1)) {
          possiblePositions.push_back({row + 1, col - 1});
        }
        if (is_enemy_position(players_turn, row + 1, col + 1)) {
          possiblePositions.push_back({row + 1, col + 1});
        }
        // WHITE Pawn
      } else {
        possiblePositions.push_back({row - 1, col});
        if (is_enemy_position(players_turn, row - 1, col - 1)) {
          possiblePositions.push_back({row - 1, col - 1});
        }
        if (is_enemy_position(players_turn, row - 1, col + 1)) {
          possiblePositions.push_back({row - 1, col + 1});
        }
      }
      break;
    // KING: can move one field in every direction
    case K:
      !is_invalid_position(row - 1) && !is_invalid_position(col) &&
                  is_enemy_position(players_turn, row - 1, col) ||
              is_free_position(row - 1, col)
          ? possiblePositions.push_back({row - 1, col})
          : void();
      !is_invalid_position(row - 1) && !is_invalid_position(col - 1) &&
                  is_enemy_position(players_turn, row - 1, col - 1) ||
              is_free_position(row - 1, col - 1)
          ? possiblePositions.push_back({row - 1, col - 1})
          : void();
      !is_invalid_position(row) && !is_invalid_position(col + 1) &&
                  is_enemy_position(players_turn, row - 1, col + 1) ||
              is_free_position(row - 1, col + 1)
          ? possiblePositions.push_back({row - 1, col + 1})
          : void();
      !is_invalid_position(row) && !is_invalid_position(col - 1) &&
                  is_enemy_position(players_turn, row, col - 1) ||
              is_free_position(row, col - 1)
          ? possiblePositions.push_back({row, col - 1})
          : void();
      !is_invalid_position(row) && !is_invalid_position(col + 1) &&
                  is_enemy_position(players_turn, row, col + 1) ||
              is_free_position(row, col + 1)
          ? possiblePositions.push_back({row, col + 1})
          : void();
      !is_invalid_position(row + 1) && !is_invalid_position(col) &&
                  is_enemy_position(players_turn, row + 1, col) ||
              is_free_position(row + 1, col)
          ? possiblePositions.push_back({row + 1, col})
          : void();
      !is_invalid_position(row + 1) && !is_invalid_position(col - 1) &&
                  is_enemy_position(players_turn, row + 1, col - 1) ||
              is_free_position(row + 1, col - 1)
          ? possiblePositions.push_back({row + 1, col - 1})
          : void();
      !is_invalid_position(row + 1) && !is_invalid_position(col + 1) &&
                  is_enemy_position(players_turn, row + 1, col + 1) ||
              is_free_position(row + 1, col + 1)
          ? possiblePositions.push_back({row + 1, col + 1})
          : void();
      break;
    // ROOK: can move vertically or horizontally until there is an enemy or ally
    case R:
      // moving vertically
      for (int i = row; i < size; i++) {
        if (!is_free_position(i, col)) {
          break;
        }
        is_enemy_position(players_turn, i, col) || is_free_position(i, col)
            ? possiblePositions.push_back({i, col})
            : void();
        if (is_enemy_position(players_turn, i, col)) {
          break;
        }
      }
      for (int i = row; i-- > 0;) {
        if (!is_free_position(i, col)) {
          break;
        }
        is_enemy_position(players_turn, i, col) || is_free_position(i, col)
            ? possiblePositions.push_back({i, col})
            : void();
        if (is_enemy_position(players_turn, i, col)) {
          break;
        }
      }
      // moving horizontal
      for (int i = col; i < size; i++) {
        if (!is_free_position(row, i)) {
          break;
        }
        is_enemy_position(players_turn, row, i) || is_free_position(row, i)
            ? possiblePositions.push_back({row, i})
            : void();
        if (is_enemy_position(players_turn, row, i)) {
          break;
        }
      }
      for (int i = col; i-- > 0;) {
        if (!is_free_position(row, i)) {
          break;
        }
        is_enemy_position(players_turn, row, i) || is_free_position(row, i)
            ? possiblePositions.push_back({row, i})
            : void();
        if (is_enemy_position(players_turn, row, i)) {
          break;
        }
      }
      break;
    case B:
      // moving diagonally right up
      for (int i = row; i-- > 0;) {
        tempCol++;
        if (is_ally_position(players_turn, i, tempCol)) {
          break;
        }
        is_enemy_position(players_turn, i, tempCol) ||
                is_free_position(i, tempCol)
            ? possiblePositions.push_back({i, tempCol})
            : void();
        if (is_enemy_position(players_turn, i, tempCol)) {
          break;
        }
      }
      tempCol = col;
      // moving diagonally left down
      for (int i = row + 1; i < size; i++) {
        tempCol--;
        if (is_ally_position(players_turn, i, tempCol)) {
          break;
        }
        is_enemy_position(players_turn, i, tempCol) ||
                is_free_position(i, tempCol)
            ? possiblePositions.push_back({i, tempCol})
            : void();
        if (is_enemy_position(players_turn, i, tempCol)) {
          break;
        }
      }
      tempCol = col;
      // moving diagonally left up
      for (int i = row; i-- > 0;) {
        tempCol--;
        if (is_ally_position(players_turn, i, tempCol)) {
          break;
        }
        is_enemy_position(players_turn, i, tempCol) ||
                is_free_position(i, tempCol)
            ? possiblePositions.push_back({i, tempCol})
            : void();
        if (is_enemy_position(players_turn, i, tempCol)) {
          break;
        }
      }
      tempCol = col;
      // moving diagonally right down
      for (int i = row + 1; i < size; i++) {
        tempCol++;
        if (is_ally_position(players_turn, i, tempCol)) {
          break;
        }
        is_enemy_position(players_turn, i, tempCol) ||
                is_free_position(i, tempCol)
            ? possiblePositions.push_back({i, tempCol})
            : void();
        if (is_enemy_position(players_turn, i, tempCol)) {
          break;
        }
      }
      tempCol = col;
      break;
      // QUEEN: can move like Rook and Bishop combined
    case Q:
      // moving vertically
      for (int i = row + 1; i < size; i++) {
        if (is_ally_position(players_turn, i, col)) {
          break;
        }
        is_enemy_position(players_turn, i, col) || is_free_position(i, col)
            ? possiblePositions.push_back({i, col})
            : void();
        if (is_enemy_position(players_turn, i, col)) {
          break;
        }
      }
      for (int i = row; i-- > 0;) {
        if (is_ally_position(players_turn, i, col)) {
          break;
        }
        is_enemy_position(players_turn, i, col) || is_free_position(i, col)
            ? possiblePositions.push_back({i, col})
            : void();
        if (is_enemy_position(players_turn, i, col)) {
          break;
        }
      }
      // moving horizontal
      for (int i = col + 1; i < size; i++) {
        if (is_ally_position(players_turn, row, i)) {
          break;
        }
        is_enemy_position(players_turn, row, i) || is_free_position(row, i)
            ? possiblePositions.push_back({row, i})
            : void();
        if (is_enemy_position(players_turn, row, i)) {
          break;
        }
      }
      for (int i = col; i-- > 0;) {
        if (is_ally_position(players_turn, row, i)) {
          break;
        }
        is_enemy_position(players_turn, row, i) || is_free_position(row, i)
            ? possiblePositions.push_back({row, i})
            : void();
        if (is_enemy_position(players_turn, row, i)) {
          break;
        }
      }
      // moving diagonally right up
      for (int i = row; i-- > 0;) {
        tempCol++;
        if (is_ally_position(players_turn, i, tempCol)) {
          break;
        }
        is_enemy_position(players_turn, i, tempCol) ||
                is_free_position(i, tempCol)
            ? possiblePositions.push_back({i, tempCol})
            : void();
        if (is_enemy_position(players_turn, i, tempCol)) {
          break;
        }
      }
      tempCol = col;
      // moving diagonally left down
      for (int i = row + 1; i < size; i++) {
        tempCol--;
        if (is_ally_position(players_turn, i, tempCol)) {
          break;
        }
        is_enemy_position(players_turn, i, tempCol) ||
                is_free_position(i, tempCol)
            ? possiblePositions.push_back({i, tempCol})
            : void();
        if (is_enemy_position(players_turn, i, tempCol)) {
          break;
        }
      }
      tempCol = col;
      // moving diagonally left up
      for (int i = row; i-- > 0;) {
        tempCol--;
        if (is_ally_position(players_turn, i, tempCol)) {
          break;
        }
        is_enemy_position(players_turn, i, tempCol) ||
                is_free_position(i, tempCol)
            ? possiblePositions.push_back({i, tempCol})
            : void();
        if (is_enemy_position(players_turn, i, tempCol)) {
          break;
        }
      }
      tempCol = col;
      // moving diagonally right down
      for (int i = row + 1; i < size; i++) {
        tempCol++;
        if (is_ally_position(players_turn, i, tempCol)) {
          break;
        }
        is_enemy_position(players_turn, i, tempCol) ||
                is_free_position(i, tempCol)
            ? possiblePositions.push_back({i, tempCol})
            : void();
        if (is_enemy_position(players_turn, i, tempCol)) {
          break;
        }
      }
      tempCol = col;
      break;
      // KNIGHT: can jump 2 fields
    case N:
      !is_invalid_position(row - 2) && !is_invalid_position(col - 1) &&
                  is_enemy_position(players_turn, row - 2, col - 1) ||
              is_free_position(row - 2, col - 1)
          ? possiblePositions.push_back({row - 2, col - 1})
          : void();
      !is_invalid_position(row - 2) && !is_invalid_position(col + 1) &&
                  is_enemy_position(players_turn, row - 2, col + 1) ||
              is_free_position(row - 2, col + 1)
          ? possiblePositions.push_back({row - 2, col + 1})
          : void();
      !is_invalid_position(row - 1) && !is_invalid_position(col + 2) &&
                  is_enemy_position(players_turn, row - 1, col + 2) ||
              is_free_position(row - 1, col + 2)
          ? possiblePositions.push_back({row - 1, col + 2})
          : void();
      !is_invalid_position(row + 1) && !is_invalid_position(col + 2) &&
                  is_enemy_position(players_turn, row + 1, col + 2) ||
              is_free_position(row + 1, col + 2)
          ? possiblePositions.push_back({row + 1, col + 2})
          : void();
      !is_invalid_position(row + 2) && !is_invalid_position(col + 1) &&
                  is_enemy_position(players_turn, row + 2, col + 1) ||
              is_free_position(row + 2, col + 1)
          ? possiblePositions.push_back({row + 2, col + 1})
          : void();
      !is_invalid_position(row + 2) && !is_invalid_position(col - 1) &&
                  is_enemy_position(players_turn, row + 2, col - 1) ||
              is_free_position(row + 2, col - 1)
          ? possiblePositions.push_back({row + 2, col - 1})
          : void();
      !is_invalid_position(row + 1) && !is_invalid_position(col - 2) &&
                  is_enemy_position(players_turn, row + 1, col - 2) ||
              is_free_position(row + 1, col - 2)
          ? possiblePositions.push_back({row + 1, col - 2})
          : void();
      !is_invalid_position(row - 1) && !is_invalid_position(col - 2) &&
                  is_enemy_position(players_turn, row - 1, col - 2) ||
              is_free_position(row - 1, col - 2)
          ? possiblePositions.push_back({row - 1, col - 2})
          : void();
      break;
      // CUSTOM FIGURES
    case M:
      // Master can go anywhere he pleases (except allied
      // positions)
      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
          is_enemy_position(players_turn, i, j) || is_free_position(i, j)
              ? possiblePositions.push_back({i, j})
              : void();
        }
      }
      break;
    case A:
      // archers can shoot enemies from 3 fields distance and then they pick up
      // their arrow
      !is_invalid_position(row + 3) && !is_invalid_position(col + 3) &&
              (is_enemy_position(players_turn, row + 3, col + 3) ||
               is_free_position(row + 3, col + 3))
          ? possiblePositions.push_back({row + 3, col + 3})
          : void();
      !is_invalid_position(row + 3) && !is_invalid_position(col) &&
              (is_enemy_position(players_turn, row + 3, col) ||
               is_free_position(row + 3, col))
          ? possiblePositions.push_back({row + 3, col})
          : void();
      !is_invalid_position(row) && !is_invalid_position(col + 3) &&
              (is_enemy_position(players_turn, row, col + 3) ||
               is_free_position(row, col + 3))
          ? possiblePositions.push_back({row, col + 3})
          : void();
      !is_invalid_position(row + 3) && !is_invalid_position(col - 3) &&
              (is_enemy_position(players_turn, row + 3, col - 3) ||
               is_free_position(row + 3, col - 3))
          ? possiblePositions.push_back({row + 3, col - 3})
          : void();
      !is_invalid_position(row) && !is_invalid_position(col - 3) &&
              (is_enemy_position(players_turn, row, col - 3) ||
               is_free_position(row, col - 3))
          ? possiblePositions.push_back({row, col - 3})
          : void();
      !is_invalid_position(row - 3) && !is_invalid_position(col + 3) &&
              (is_enemy_position(players_turn, row - 3, col + 3) ||
               is_free_position(row - 3, col + 3))
          ? possiblePositions.push_back({row - 3, col + 3})
          : void();
      !is_invalid_position(row - 3) && !is_invalid_position(col + 3) &&
              (is_enemy_position(players_turn, row - 3, col) ||
               is_free_position(row - 3, col))
          ? possiblePositions.push_back({row - 3, col})
          : void();
      !is_invalid_position(row - 3) && !is_invalid_position(col + 3) &&
              (is_enemy_position(players_turn, row - 3, col - 3) ||
               is_free_position(row - 3, col - 3))
          ? possiblePositions.push_back({row - 3, col - 3})
          : void();
      break;
    default:
      break;
  }
  /* Check if there are any possible positions. If not - Player has to pick
     another figure */
  if (possiblePositions.empty()) {
    return false;
  }
  return true;
}

bool Chessboard::can_move_selection_to(int row, int col) const {
  bool validPosition = false;

  std::vector<Pos>::iterator it = std::find_if(
      begin(possiblePositions), end(possiblePositions), [&](const Pos& p) {
        if (p.row == row && p.column == col) {
          if (is_enemy_position(players_turn, p.row, p.column) ||
              is_free_position(p.row, p.column)) {
            validPosition = true;
            return true;
          }
        } else {
          return false;
        }
      });
  return validPosition;
}

void Chessboard::move_selection_to(int row, int col) {
  /* figure will be moved to valid position
     if this is an enemy position - game will check if this will lead to a win
   */
  if (is_enemy_position(players_turn, row, col)) {
    if (board[row][col] != NULL) {
      board[row][col]->kill();
    }
    check_game_over();
    board[row][col] = NULL;
  }
  board[row][col] = board[selectedFigure.row][selectedFigure.column];
  board[selectedFigure.row][selectedFigure.column] = NULL;
  cout << "Figure moved to (" << row << "|" << col << ")" << endl;
  possiblePositions.clear();
  players_turn == WHITE ? players_turn = BLACK : players_turn = WHITE;
}

bool Chessboard::is_possible_position(int row, int col) const {
  /* iterating through the possible positions
     if this position is marked as a possible position it will be marked in the
     ouput with brackets */
  Pos currentPosition = {row, col};
  bool positionFound = false;

  std::vector<Pos>::iterator it = std::find_if(
      begin(possiblePositions), end(possiblePositions), [&](const Pos& p) {
        if (p.row == currentPosition.row &&
            p.column == currentPosition.column) {
          if (is_enemy_position(players_turn, p.row, p.column) ||
              is_free_position(p.row, p.column)) {
            positionFound = true;
            return true;
          }
        } else {
          return false;
        }
      });
  return positionFound;
}

void Chessboard::show(bool figure_selected) const {
  printf("\n");
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
                cout << "[";
                printf("%c", tolower(this->board[i][j]->get_symbol()));
                cout << "]";
              } else {
                cout << "[";
                printf("%c", this->board[i][j]->get_symbol());
                cout << "]";
              }
            } else {
              printf("%3s", "[.]");
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
            // empty fields are marked as dots
            printf("%3c", '.');
          }
        }
      }
    }
    printf("\n");
  }
  printf("\n");
}
