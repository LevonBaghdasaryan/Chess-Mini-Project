#include "ChessPiece.hpp"
#include "ChessBoard.hpp"
#include "king.hpp"
#include "queen.hpp"
#include "rook.hpp"
#include "bishop.hpp"
#include "knight.hpp"
#include "pawn.hpp"

int main() {

    ChessBoard board;

    // White Figurs
    King whiteKing(PieceColor::White); 
    Queen whiteQueen(PieceColor::White);
    Rook whiteRook(PieceColor::White);
    Bishop whiteBishop(PieceColor::White);
    Knight whiteKnight(PieceColor::White);
    Pawn whitePawn(PieceColor::White);

    // Black Figurs
    King blackKing(PieceColor::Black);
    // Queen blackQueen(PieceColor::Black);
    // Rook blackRook(PieceColor::Black);
    // Bishop blackBishop(PieceColor::Black);
    // Knight blackKnight(PieceColor::Black);
    // Pawn blackPawn(PieceColor::Black);

    board.placePiece(&blackKing, 'C', 8);

    board.placePiece(&whiteQueen, 'G', 7);
    board.placePiece(&whiteRook, 'H', 8);
    // board.placePiece(&whiteBishop, 'F', 3);
    // board.placePiece(&whiteRook, 'G', 4);
    // board.placePiece(&whiteKnight, 'F', 6);

    board.print();

    if (board.isCheck(PieceColor::Black)) {
        if (board.isCheckMate(PieceColor::Black)) {
            std::cout << "Black king is in checkmate. " << std::endl;
        }
        else {
            std::cout << "Black king is in check. " << std::endl;
        }
    } else {
        std::cout << "Black king is not in check. " << std::endl;
    }

    return 0;
}