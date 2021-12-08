#pragma once
#include "Chessman.h"

class Pawn : public Chessman {
 protected:
  const char symbol{P};

 public:
  explicit Pawn(bool is_white = WHITE);
  virtual ~Pawn() {}
  virtual char get_symbol() const { return this->symbol; }
  virtual int get_color() const { return this->color; }
  virtual bool is_white() const { return this->color == 0 ? true : false; }
  virtual bool is_essential() const { return isEssential; }
  void get_info() const;
  //virtual bool can_move(int from_row, int from_col, int to_row, int to_col,
  //                      const Chessboard &cb) const override;
};
