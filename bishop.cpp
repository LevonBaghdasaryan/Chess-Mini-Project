#include "bishop.hpp"

Bishop::Bishop(PieceColor color) : ChessPiece(PieceType::Bishop, color) {}

char Bishop::getType() const {
    return 'B';
}

char Bishop::getColor() const {
    return _color == PieceColor::White ? 'W' : 'B';
}