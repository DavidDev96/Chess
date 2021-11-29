#pragma once
#include "Chessman.h"
class King : public Chessman {
  protected:
  int color{WHITE};             // White = 0, Black = 1
  const char symbol{'K'};       // Q for Queens, K for Kings, R for Rooks, B for Bishops, K
                                // for Knights, P fo Pawns
  const bool isEssential{0};    // will lead to a game over if loss
  struct Pos {
      int x {0};
      int y {0};
  } position;
  public: 
   King(char symbol, bool is_white);
   virtual ~King() {}
   char get_symbol() const;
   int get_color() const;
   bool is_white() const;
   virtual bool is_essential() const { return false; }
   virtual bool can_move(int from_row, int from_col, int to_row, int to_col,
                         const Chessboard &cb) const = 0;
};
