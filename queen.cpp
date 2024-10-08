#include "queen.hpp"

Queen::Queen(PieceColor color) : ChessPiece(PieceType::Queen, color) {}

char Queen::getType() const {
    return 'Q';
}

char Queen::getColor() const {
    return _color == PieceColor::White ? 'W' : 'B';
}