#include "pawn.hpp"

Pawn::Pawn(PieceColor color) : ChessPiece(PieceType::Pawn, color) {}

char Pawn::getType() const {
    return 'P';
}

char Pawn::getColor() const {
    return _color == PieceColor::White ? 'W' : 'B';
}