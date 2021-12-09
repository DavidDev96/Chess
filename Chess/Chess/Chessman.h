#pragma once

#include <iostream>
#include <ostream>

using namespace std;

enum Figures {
  // STANDARD FIGURES:
  K = 'K',  // King
  Q = 'Q',  // Queen
  B = 'B',  // Bishop
  R = 'R',  // Rook
  N = 'N',  // Knight
  P = 'P',  // Pawn
  // CUSTOM FIGURES:
  M = 'M',  // Master
  A = 'A'   // Archer
};
enum Colors { WHITE = 1, BLACK = 0 };

class Chessman {
 protected:   // only visible for inherited objects
  int color;  // White = 1, Black = 0
  char symbol{P};
  bool isEssential{false};  // will lead to a game over if loss
  bool isSelected{false};

 public:
  bool hasFallen{false};
  explicit Chessman(char symbol = P, bool is_white = WHITE);
  virtual ~Chessman() {}
  virtual char get_symbol() const { return symbol; }
  virtual int get_color() const { return color; }
  virtual bool has_fallen() const { return hasFallen; }
  virtual bool is_white() const { return color == WHITE; }
  virtual bool is_essential() const { return isEssential; }
  virtual bool is_selected() const { return isSelected; }
  virtual void kill();
};
