#ifndef __PAWN_HPP__
#define __PAWN_HPP__

#include "ChessPiece.hpp"

class Pawn : public ChessPiece {
    public:
        Pawn(PieceColor color);

        char getType() const override;
        char getColor() const override;
};

#endif // __PAWN_HPP__