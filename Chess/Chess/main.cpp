#include <iostream>
#include "Chessboard.h"

using namespace std;

bool is_position_valid(Chessboard &cb, Pos figurePos, int currentPlayer) {
    return cb.is_invalid_position(figurePos.row) ||
           cb.is_invalid_position(figurePos.column) ||
           cb.is_free_position(figurePos.row, figurePos.column) ||
           cb.is_enemy_position(currentPlayer, figurePos.row, figurePos.column) ||
           !cb.selected_piece_valid(figurePos.row, figurePos.column);
}

int main() {
  int currentPlayer = WHITE;
  bool game_over = false;
  Pos figurePos = {0, 0};
  Pos destPos = {0, 0};

  Chessboard cb;
  cb.create_figures();
  cout << endl << "------ Game started -------" << endl;
  cb.show();

  while (!game_over) {
    cb.is_whites_turn() ? printf("White's turn:\n") : printf("Black's turn:\n");
    cout << "Pick a figure! Enter the position (row|col): " << endl;
    cin >> figurePos.row >> figurePos.column;

    while (is_position_valid(cb, figurePos, currentPlayer)) {
      cout << "Cannot select this position (" << figurePos.row << ":"
           << figurePos.column
           << ") = empty or enemy or blocked. Try again (row|col).." << endl;
      cin >> figurePos.row >> figurePos.column;
    }

    if (cb.selected_piece_valid(figurePos.row, figurePos.column)) {
      cb(figurePos.row, figurePos.column);
      cb.show(true);
      cout
          << "Enter the position where you want to place the figure (row|rol): "
          << endl;
      cin >> destPos.row >> destPos.column;
    }

    while (!cb.can_move_selection_to(destPos.row, destPos.column)) {
      cout << "Cannot place the figure here.Try again (row|col)" << endl;
      cin >> destPos.row >> destPos.column;
    }

    cb.move_selection_to(destPos.row, destPos.column);
    cb.show();
    game_over = cb.get_game_over();
    currentPlayer == WHITE ? currentPlayer = BLACK : currentPlayer = WHITE;
  }
  cout << endl << "------ Game finished -------" << endl;
  return 0;
}