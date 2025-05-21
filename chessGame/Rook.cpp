#include "Rook.h"
#include <vector>
#include "Plateau.h"
#include "Piece.h"


using namespace std;

Rook::Rook(bool isWhite, QString& imagePath) : Piece(isWhite, imagePath)
{
    _deplacement = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
}

Rook::Rook(int currentRow, int currentColumn, bool isWhite, QString& imagePath) : Piece(currentRow, currentColumn, isWhite, imagePath)
{
    _deplacement = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
}

bool Rook::possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool& isCaptured, Plateau* plateau) const {
    int dRow = newRow - currentRow;
    int dCol = newColumn - currentColumn;

    if (dRow != 0 && dCol != 0) return false;

    int stepRow = (dRow == 0) ? 0 : (dRow > 0 ? 1 : -1);
    int stepCol = (dCol == 0) ? 0 : (dCol > 0 ? 1 : -1);

    int r = currentRow + stepRow;
    int c = currentColumn + stepCol;

    while (r != newRow || c != newColumn) {
        if (plateau->getPiece(r, c) != nullptr) {
            return false;
        }
        r += stepRow;
        c += stepCol;
    }

    Piece* target = plateau->getPiece(newRow, newColumn);
    if (target == nullptr) {
        isCaptured = false;
        return true;
    }
    else if (target->isWhite() != this->isWhite()) {
        isCaptured = true;
        return true;
    }

    return false;
}

std::string Rook::getType() const
{
	return "rook";
}

Piece* Rook::clone() const
{
	return new Rook(*this);
}