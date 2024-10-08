#ifndef __KING_HPP__
#define __KING_HPP__

#include "ChessPiece.hpp"

class King : public ChessPiece {
    public:
        King(PieceColor color);

        char getType() const override;
        char getColor() const override;
};

#endif // __KING_HPP__
