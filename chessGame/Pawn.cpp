#include "Pawn.h"
#include "Plateau.h"

bool Pawn::possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool& isCaptured, Plateau* plateau) const
{
    int deltaRow = newRow - currentRow;
    int deltaCol = newColumn - currentColumn;

    Piece* dest = plateau->getPiece(newRow, newColumn);

 
    if ((deltaCol == 0) && dest == nullptr)
    {
       
        if (deltaRow == (_isWhite ? -1 : 1))
            return true;

        if (deltaRow == (_isWhite ? -2 : 2) && currentRow == (_isWhite ? 6 : 1))
        {
            int stepRow = _isWhite ? -1 : 1;
            if (plateau->getPiece(currentRow + stepRow, currentColumn) == nullptr)
                return true;
        }

        return false;
    }
    if (abs(deltaCol) == 1 && deltaRow == (_isWhite ? -1 : 1))
    {
        if (dest != nullptr && dest->isWhite() != this->_isWhite)
        {
            isCaptured = true;
            return true;
        }
    }

    return false;
}

Pawn::Pawn(bool isWhite, QString& imagePath) : Piece(isWhite, imagePath)
{
    _deplacement = { { 2, 1 }, { 1, 2 }, { -1, 2 }, { -2, 1 },
    { -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 } };
}

Pawn::Pawn(int currentRow, int currentColumn, bool isWhite, QString& imagePath) : Piece(currentRow, currentColumn, isWhite, imagePath)
{
    {
        if (_isWhite)
        {
            _deplacement = { { -1, 0 }, { -1, -1 }, { -1, 1 } };
        }
        else
        {
            _deplacement = { { -1, 0 }, { -1, -1 }, { -1, 1 } };
        }
    }
}

std::string Pawn::getType() const
{
    return "pawn";
}

Piece* Pawn::clone() const
{
	return new Pawn(*this);
}