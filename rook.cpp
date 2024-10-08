#include "rook.hpp"

Rook::Rook(PieceColor color) : ChessPiece(PieceType::Rook, color) {}

char Rook::getType() const {
    return 'R';
}

char Rook::getColor() const {
    return _color == PieceColor::White ? 'W' : 'B';
}
