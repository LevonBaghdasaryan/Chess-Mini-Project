#ifndef __CHESS_PIECE_HPP__
#define __CHESS_PIECE_HPP__

#include <iostream>
#include <string>

enum class PieceType {
    King,
    Queen,
    Rook,
    Bishop,
    Knight,
    Pawn
};

enum class PieceColor {
    White,
    Black
};

class ChessPiece {
    public:
        ChessPiece(PieceType type, PieceColor color);

        virtual char getType() const = 0;
        virtual char getColor() const = 0;

    protected:
        PieceType _type; 
        PieceColor _color;
};

#endif // __CHESS_PIECE_HPP__
