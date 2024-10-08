#ifndef __QUEEN_HPP__
#define __QUEEN_HPP__

#include "ChessPiece.hpp"

class Queen : public ChessPiece {
    public:
        Queen(PieceColor color);

        char getType() const override;
        char getColor() const override;
};

#endif // __QUEEN_HPP__