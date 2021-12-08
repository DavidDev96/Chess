#pragma once

#include <iostream>
#include <ostream>
using namespace std;

// Q for Queens, K for Kings, R for Rooks, B for Bishops, K for Knights, P for
// Pawns
enum Figures { K = 'K', Q = 'Q', B = 'B', R = 'R', N = 'N', P = 'P' };
enum Colors { WHITE = 1, BLACK = 0 };

struct Pos {
  int row{0};
  int column{0};
};

class Chessman {
 protected:          // only visible for inherited objects
  int color{-1};  // White = 1, Black = 0
  char symbol{P};
  bool isEssential{false};  // will lead to a game over if loss
  bool hasFallen{false};
  bool isSelected{false};
  Pos position;

 public:
  explicit Chessman(char symbol = P, bool is_white = WHITE);
  virtual ~Chessman() {}
  virtual char get_symbol() const { return symbol; }
  virtual int get_color() const { return color; }
  virtual bool has_fallen() const { return hasFallen; }
  virtual bool is_white() const { return color == WHITE; }
  virtual bool is_essential() const { return isEssential; }
  virtual bool is_selected() const { return isSelected; }
  virtual void get_info() const;
};
