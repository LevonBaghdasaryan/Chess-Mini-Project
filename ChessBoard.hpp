#ifndef __CHESS_BOARD_HPP__
#define __CHESS_BOARD_HPP__

#include <iostream>
#include "ChessPiece.hpp"

class ChessBoard {
    public:
        ChessBoard();
        
        void placePiece(ChessPiece* piece, const char& file, const int &rank);
        void print() const;
        bool isCheck(PieceColor kingColor) const;
        bool isCheckMate(PieceColor kingColor);

    private:
        ChessPiece* _board[8][8];

        // ---------------------
        // King
        int _whiteKingCount = 0;
        int _blackKingCount = 0;

        // Queen
        int _whiteQueenCount = 0;
        int _blackQueenCount = 0;

        // Rook
        int _whiteRookCount = 0;
        int _blackRookCount = 0;

        // Bishop
        int _whiteBishopCount = 0;
        int _blackBishopCount = 0;

        // Knight
        int _whiteKnightCount = 0;
        int _blackKnightCount = 0;

        // Pawn
        int _whitePawnCount = 0;
        int _blackPawnCount = 0;
        // -----------------------

        bool isValidPosition(const char& file,const int& rank) const;
        bool canPlaceKing(const char& file,const int& rank) const;
        bool isInCheck(int kingFileIndex, int kingRankIndex, PieceColor kingColor) const;
        bool hasLegalMoves(int kingFileIndex, int kingRankIndex, PieceColor kingColor);
};

#endif // __CHESS_BOARD_HPP__