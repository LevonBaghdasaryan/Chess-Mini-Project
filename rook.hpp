#ifndef __ROOK_HPP__
#define __ROOK_HPP__

#include "ChessPiece.hpp"

class Rook : public ChessPiece {
    public:
        Rook(PieceColor color);

        char getType() const override;
        char getColor() const override;
};

#endif // __ROOK_HPP__