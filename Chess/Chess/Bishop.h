#pragma once
#include "Chessman.h"

class Bishop : public Chessman {
 protected:
  int color;
  const char symbol{B};

 public:
  explicit Bishop(bool is_white = WHITE);
  virtual ~Bishop() {}
  virtual char get_symbol() const { return this->symbol; }
  virtual int get_color() const { return this->color; }
  virtual bool is_white() const { return this->color == 0 ? true : false; }
  virtual bool is_essential() const { return isEssential; }
};
