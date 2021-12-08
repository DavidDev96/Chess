#pragma once
#include "Chessman.h"

class Queen : public Chessman {
 protected:
  const char symbol{Q};

 public:
  explicit Queen(bool is_white = WHITE);
  virtual ~Queen() {}
  char get_symbol() const { return this->symbol; }
  int get_color() const { return this->color; }
  bool is_white() const { return this->color == 0 ? true : false; }
  virtual bool is_essential() const { return isEssential; }
  virtual void get_info() const;
  //virtual bool can_move(int from_row, int from_col, int to_row, int to_col,
  //                      const Chessboard &cb) const override;
};
