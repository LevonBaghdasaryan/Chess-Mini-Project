#include "ChessBoard.hpp"
#include "king.hpp"
#include "queen.hpp"
#include "rook.hpp"
#include "bishop.hpp"
#include "knight.hpp"
#include "pawn.hpp"


ChessBoard::ChessBoard() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            _board[i][j] = nullptr;
        }
    }
}

bool ChessBoard::isValidPosition(const char& file, const int& rank) const {
    int fileIndex = file - 'A';
    int rankindex = 8 - rank;
    return fileIndex >= 0 && fileIndex < 8 && rankindex >= 0 && rankindex < 8;
}

bool ChessBoard::canPlaceKing(const char& file,const int& rank) const {
    int fileIndex = file - 'A';
    int rankindex = 8 - rank;

    for(int i = -1; i <= 1; ++i) {
        for(int j = -1; j <= 1; ++j) {

            int newFileIndex = fileIndex + i;
            int newRankIndex = rankindex + j;
            
            if(isValidPosition(newFileIndex + 'A', 8 - newRankIndex) && _board[newRankIndex][newFileIndex] != nullptr) {
                if(_board[newRankIndex][newFileIndex]->getType() == 'K') {
                    return false;
                }
            }
        }
    }
    return true;
}

void ChessBoard::placePiece(ChessPiece* piece, const char& file, const int& rank) {
    int fileIndex = file - 'A';
    int rankindex = 8 - rank;

    if(!isValidPosition(file, rank)) {
        std::cout << "Invalid position." << std::endl;
        return;
    }
    
    if(_board[rankindex][fileIndex] != nullptr) {
        std::cout << "Position " << file << rank << " is already occupied." << std::endl;
        return;
    }      

    switch (piece->getType()) {
        case 'Q': // Queen

            if (piece->getColor() == 'W' && _whiteQueenCount >= 9) {
                std::cout << "Cannot place more than 9 white queens on the board." << std::endl;
                return;
            } 
            else if (piece->getColor() == 'B' && _blackQueenCount >= 9) {
                std::cout << "Cannot place more than 9 black queens on the board." << std::endl;
                return;
            }

            piece->getColor() == 'W' ? ++_whiteQueenCount : ++_blackQueenCount;
            break;

        case 'K': // King

            if (piece->getColor() == 'W' && _whiteKingCount >= 1) {
                std::cout << "Cannot place more than one white king on the board." << std::endl;
                return;
            } 
            else if (piece->getColor() == 'B' && _blackKingCount >= 1) {
                std::cout << "Cannot place more than one black king on the board." << std::endl;
                return;
            }
            if (!canPlaceKing(file, rank)) {
                std::cout << "Cannot place two kings next to each other." << std::endl;
                return;
            }

            piece->getColor() == 'W' ? ++_whiteKingCount : ++_blackKingCount;
            break;

        case 'R': // Rook

            if (piece->getColor() == 'W' && _whiteRookCount >= 10) {
                std::cout << "Cannot place more than 10 white rooks on the board." << std::endl;
                return;
            } 
            else if (piece->getColor() == 'B' && _blackRookCount >= 10) {
                std::cout << "Cannot place more than 10 black rooks on the board." << std::endl;
                return;
            }

            piece->getColor() == 'W' ? ++_whiteRookCount : ++_blackRookCount;
            break;

        case 'B': // Bishop
            if (piece->getColor() == 'W' && _whiteBishopCount >= 10) {
                std::cout << "Cannot place more than 10 white bishops on the board." << std::endl;
                return;
            } 
            else if (piece->getColor() == 'B' && _blackBishopCount >= 10) {
                std::cout << "Cannot place more than 10 black bishops on the board." << std::endl;
                return;
            }

            piece->getColor() == 'W' ? ++_whiteBishopCount : ++_blackBishopCount;
            break;

        case 'k': // knight
            if (piece->getColor() == 'W' && _whiteKnightCount >= 10) {
                std::cout << "Cannot place more than 10 white knights on the board." << std::endl;
                return;
            }
            else if (piece->getColor() == 'B' && _blackKnightCount >= 10) {
                std::cout << "Cannot place more than 10 black knights on the board." << std::endl;
                return;
            }

            piece->getColor() == 'W' ? ++_whiteKnightCount : ++_blackKnightCount;
            break;

        case 'P': // Pawn

            if (piece->getColor() == 'W' && _whitePawnCount >= 8) {
                std::cout << "Cannot place more than 8 white pawns on the board." << std::endl;
                return;
            } 
            else if (piece->getColor() == 'B' && _blackPawnCount >= 8) {
                std::cout << "Cannot place more than 8 black pawns on the board." << std::endl;
                return;
            }

            piece->getColor() == 'W' ? ++_whitePawnCount : ++_blackPawnCount;
            break;

        default:
            std::cout << "Unknown piece type." << std::endl;
            return;
    }


    _board[rankindex][fileIndex] = piece;
}

void ChessBoard::print() const {

    std::cout << "Chess Board: " << std::endl;
    char a[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    std::cout << "   __ __ __ __ __ __ __ __" << std::endl;

    for(std::size_t i = 0; i < 8; ++i) {
        std::cout << 8 - i << " ";
        std::cout << "|";
        for(std::size_t j = 0; j < 8; ++j) {
            if(_board[i][j] != nullptr) {
                std::cout << _board[i][j]->getColor() <<  _board[i][j]->getType();
            }
            else {
                std::cout << "__";
            }
            std::cout << "|";
        }
        std::cout << std::endl;   
    }

    std::cout << "   ";   
    for(std::size_t i = 0; i < 8; ++i) {
        std::cout << a[i] << "  ";
    }
    std::cout << std::endl;   
}

bool ChessBoard::isInCheck(int kingFileIndex, int kingRankIndex, PieceColor kingColor) const {
    int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},         {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    char opponentColor = ((kingColor == PieceColor::White) ? 'B' : 'W');

    // Check for Queen threats
    for (std::size_t i = 0; i < 4; ++i) {
        int file = kingFileIndex + directions[i][0];
        int rank = kingRankIndex + directions[i][1];

        while (isValidPosition(file + 'A', 8 - rank)) {
            ChessPiece* piece = _board[rank][file];
            if (piece != nullptr) {
                if (piece->getColor() == opponentColor && piece->getType() == 'Q') {
                    return true;
                }
                else {
                    break;
                }    
            }
            file += directions[i][0];
            rank += directions[i][1];
        }
    }

    // Check for Rook threats
    for (std::size_t i = 0; i < 8; ++i) {
        int file = kingFileIndex + directions[i][0];
        int rank = kingRankIndex + directions[i][1];

        while (isValidPosition(file + 'A', 8 - rank)) {
            ChessPiece* piece = _board[rank][file];
            if (piece != nullptr) {
                if (piece->getColor() == opponentColor && piece->getType() == 'R') {
                    return true;
                }
                else {
                    break;
                }    
            }
            file += directions[i][0];
            rank += directions[i][1];
        }
    }

    // Check for Queen threats
    for (std::size_t i = 4; i < 8; ++i) {
        int file = kingFileIndex + directions[i][0];
        int rank = kingRankIndex + directions[i][1];

        while (isValidPosition(file + 'A', 8 - rank)) {
            ChessPiece* piece = _board[rank][file];
            if (piece != nullptr) {
                if (piece->getColor() == opponentColor &&  piece->getType() == 'Q') {
                    return true;
                }
                else {
                    break;
                }  
            }
            file += directions[i][0];
            rank += directions[i][1];
        }
    }

    // Check for Bishop threats
    for (std::size_t i = 4; i < 8; ++i) {
        int file = kingFileIndex + directions[i][0];
        int rank = kingRankIndex + directions[i][1];

        while (isValidPosition(file + 'A', 8 - rank)) {
            ChessPiece* piece = _board[rank][file];
            if (piece != nullptr) {
                if (piece->getColor() == opponentColor && piece->getType() == 'B') {
                    return true;
                }
                else {
                    break;
                }  
            }
            file += directions[i][0];
            rank += directions[i][1];
        }
    }


    // Check for Knight threats
    int knightMoves[8][2] = {
        {-2, -1}, {-2, 1},
        {-1, -2}, {-1, 2},
        {1, -2}, {1, 2},
        {2, -1}, {2, 1}
    };

    for (std::size_t i = 0; i < 8; ++i) {
        int file = kingFileIndex + knightMoves[i][0];
        int rank = kingRankIndex + knightMoves[i][1];

        if (isValidPosition(file + 'A', 8 - rank)) {
            ChessPiece* piece = _board[rank][file];
            if (piece != nullptr && piece->getColor() == opponentColor && piece->getType() == 'k') {
                return true;
            }
        }
    }

    // Check for Pawn threats
    int pawnDirection = (kingColor == PieceColor::White) ? 1 : -1;
    int pawnMoves[2][2] = {
        {pawnDirection, -1},
        {pawnDirection, 1}
    };

    for (std::size_t i = 0; i < 2; ++i) {
        int file = kingFileIndex + pawnMoves[i][0];
        int rank = kingRankIndex + pawnMoves[i][1];

        if (isValidPosition(file + 'A', 8 - rank)) {
            ChessPiece* piece = _board[rank][file];
            if (piece != nullptr && piece->getColor() == opponentColor && piece->getType() == 'P') {
                return true;
            }
        }
    }

    return false;
}

bool ChessBoard::hasLegalMoves(int kingFileIndex, int kingRankIndex, PieceColor kingColor) {
    int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},         {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    for (std::size_t i = 0; i < 8; ++i) {
        int newFile = kingFileIndex + directions[i][0];
        int newRank = kingRankIndex + directions[i][1];

        if (isValidPosition(newFile + 'A', 8 - newRank)) {
            ChessPiece* piece = _board[newRank][newFile];
            if (piece == nullptr || piece->getColor() != ((kingColor == PieceColor::White) ? 'W' : 'B')) {

                ChessPiece* originalPiece = _board[kingRankIndex][kingFileIndex];
                _board[kingRankIndex][kingFileIndex] = nullptr;
                _board[newRank][newFile] = originalPiece;

                // if (!isInCheck(newFile, newRank, kingColor)) {
                //     return true;
                // }

                if (!isInCheck(newFile, newRank, kingColor)) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool ChessBoard::isCheck(PieceColor kingColor) const {
    int kingFileIndex = -1;
    int kingRankIndex = -1;

    for (std::size_t i = 0; i < 8; ++i) {
        for (std::size_t j = 0; j < 8; ++j) {
            ChessPiece* piece = _board[i][j];
            if (piece != nullptr && piece->getType() == 'K' && piece->getColor() == ((kingColor == PieceColor::White) ? 'W' : 'B')) {
                kingFileIndex = j;
                kingRankIndex = i;
                break;
            }
        }
        if (kingFileIndex != -1) break;
    }

    if (kingFileIndex == -1 || kingRankIndex == -1) {
        std::cout << "Error: King not found on the board. " << std::endl;
        return false; // King not found on the board
    }

    return isInCheck(kingFileIndex, kingRankIndex, kingColor);
}

bool ChessBoard::isCheckMate(PieceColor kingColor) {

    if (!isCheck(kingColor)) return false;

    int kingFileIndex = -1;
    int kingRankIndex = -1;

    for (std::size_t i = 0; i < 8; ++i) {
        for (std::size_t j = 0; j < 8; ++j) {
            ChessPiece* piece = _board[i][j];
            if (piece != nullptr && piece->getType() == 'K' && piece->getColor() == ((kingColor == PieceColor::White) ? 'W' : 'B')) {
                kingFileIndex = j;
                kingRankIndex = i;
                break;
            }
        }
        if (kingFileIndex != -1) break;
    }

    if (kingFileIndex == -1 || kingRankIndex == -1) {
        std::cout << "Error: King not found on the board." << std::endl;
        return false; // King not found on the board
    }


    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            ChessPiece* piece = _board[i][j];
            if (piece != nullptr && piece->getColor() == ((kingColor == PieceColor::White) ? 'W' : 'B')) {

                ChessPiece* capturedPiece = _board[kingRankIndex][kingFileIndex];
                _board[kingRankIndex][kingFileIndex] = nullptr;
                _board[i][j] = capturedPiece;

                if (!isInCheck(kingFileIndex, kingRankIndex, kingColor)) {
                    _board[i][j] = piece;
                    _board[kingRankIndex][kingFileIndex] = capturedPiece;
                    return false;
                }

                _board[i][j] = piece;
                _board[kingRankIndex][kingFileIndex] = capturedPiece;
            }
        }
    }
    
    return !hasLegalMoves(kingFileIndex, kingRankIndex, kingColor);
}