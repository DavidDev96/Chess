#include <iostream>

#include "Chessboard.h"

using namespace std;
void create_figures() {}

int main() {
  int player = WHITE;
  bool game_over = false;
  Pos figurePos = {0, 0};
  Pos destPos = {0, 0};

  Chessboard cb;
  cb.create_figures();

  //cb.show();
  //cout << "Figur auf Position (6,6) ist: " << cb(6, 6)->get_symbol() << endl;
  //cout << "Zug von 6|6 zu 5|6 moeglich: " << cb.can_move(6, 6, 5, 6) << endl;
  //cout << "Zug von 6|6 zu 5|5 moeglich: " << cb.can_move(6, 6, 5, 5) << endl;
  //cout << "Zug von 6|6 zu 5|6 moeglich: " << cb.can_move(6, 6, 7, 6) << endl;
  //cout << "Zug von 6|3 zu 8|6 moeglich: " << cb.can_move(6, 3, 8, 6) << endl;

  cout << endl << "------- Game started ---------" << endl;

  cb.show();
  while (!game_over) {
    cb.is_whites_turn() ? printf("White's turn:\n") : printf("Black's turn:\n");
    cout << "Pick a figure! Enter the position (row|col): " << endl;
    cin >> figurePos.row >> figurePos.column;
    while (cb.is_free_position(figurePos.row, figurePos.column)) {
      cout << "Cannot select empty position (" << figurePos.row << ":"
           << figurePos.column << "). Try again (row|col).." << endl;
      cin >> figurePos.row >> figurePos.column;
    }
    while (cb.is_enemy_position(player, figurePos.row, figurePos.column)) {
      cout << "Cannot select enemy's position (" << figurePos.row << ":"
           << figurePos.column << "). Try again (row|col).." << endl;
      cin >> figurePos.row >> figurePos.column;
    }

    cb.select_piece(figurePos.row, figurePos.column);
    cout << "Enter the position where you want to place the figure (row|rol): "
         << endl;
    cin >> destPos.row >> destPos.column;
    while (!cb.can_move_selection_to(destPos.row, destPos.column)) {
      cout << "Cannot place the figure here.Try again (row|col)" << endl;
      cin >> destPos.row >> destPos.column;
    }
    cb.move_selection_to(destPos.row, destPos.column);
    cb.show();
    game_over = cb.is_game_over();
    player == WHITE ? player = BLACK : player = WHITE;
  }
  return 0;
}