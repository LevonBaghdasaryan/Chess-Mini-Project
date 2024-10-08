#ifndef __BISHOP_HPP__
#define __BISHOP_HPP__

#include "ChessPiece.hpp"

class Bishop : public ChessPiece {
    public:
        Bishop(PieceColor color);

        char getType() const override;
        char getColor() const override;
};

#endif // __BISHOP_HPP__