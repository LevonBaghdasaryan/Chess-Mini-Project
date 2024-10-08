#include "king.hpp"

King::King(PieceColor color) : ChessPiece(PieceType::King, color) {}

char King::getType() const {
    return 'K';
}

char King::getColor() const {
    return _color == PieceColor::White ? 'W' : 'B';
}