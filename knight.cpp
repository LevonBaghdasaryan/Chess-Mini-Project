#include "knight.hpp"

Knight::Knight(PieceColor color) : ChessPiece(PieceType::Knight, color) {}

char Knight::getType() const {
    return 'k';
}

char Knight::getColor() const {
    return _color == PieceColor::White ? 'W' : 'B';
}