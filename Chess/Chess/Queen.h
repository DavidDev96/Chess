#pragma once
#include "Chessman.h"

class Queen : public Chessman {
 protected:
  const char symbol{Q};

 public:
  explicit Queen(bool is_white = WHITE);
  virtual ~Queen() {}
  virtual char get_symbol() const { return this->symbol; }
  virtual int get_color() const { return this->color; }
  virtual bool is_white() const { return this->color == 0 ? true : false; }
  virtual bool is_essential() const { return isEssential; }
};
