#pragma once

#include <ostream>
#include "Chessboard.h"

const int WHITE = 0;
const int BLACK = 1;

class Chessman {

    protected:                  // only visible for inherited objects
      int color{WHITE};         // White = 0, Black = 1
      char symbol{'P'};         // Q for Queens, K for Kings, R for Rooks, B for Bishops, K
                                // for Knights, P fo Pawns
      bool isEssential{0};      // will lead to a game over if loss
    public:
        

    public:
        Chessman(char symbol, bool is_white);
        virtual ~Chessman() {}
        char get_symbol() const;
        char get_color() const;
        bool is_white() const;
        virtual bool is_essential() const { return false; }
        virtual bool can_move(int from_row, int from_col, int to_row,
                              int to_col, const Chessboard &cb) const = 0;
};

};
