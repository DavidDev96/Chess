#pragma once
#include "Chessman.h"

class Archer : public Chessman {
 protected:
  const char symbol{A};
  const bool isEssential{1};  // will lead to a game over if loss
 public:
  explicit Archer(bool is_white = WHITE);
  virtual ~Archer() {}
  virtual char get_symbol() const { return this->symbol; }
  virtual int get_color() const { return this->color; }
  virtual bool is_white() const { return this->color == 0 ? true : false; }
  virtual bool is_essential() const { return isEssential; }
  virtual void get_info() const;
};
