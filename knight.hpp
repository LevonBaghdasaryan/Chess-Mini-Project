#ifndef __KNIGHT_HPP__
#define __KNIGHT_HPP__

#include "ChessPiece.hpp"

class Knight : public ChessPiece {
    public:
        Knight(PieceColor color);

        char getType() const override;
        char getColor() const override;
};

#endif // __KNIGHT_HPP__