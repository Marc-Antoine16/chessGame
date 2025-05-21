#include "King.h"


King::King(bool isWhite, QString& imagePath) : Piece(isWhite, imagePath)
{
	_deplacement = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1},  {1, 0},  {1, 1} };
}

King::King(int currentRow, int currentColumn, bool isWhite, QString& imagePath) : Piece(currentRow, currentColumn, isWhite, imagePath)
{
	_deplacement = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1},  {1, 0},  {1, 1} };
}

bool King::possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool& isCaptured, Plateau* plateau) const
{
    Piece* dest = plateau->getPiece(newRow, newColumn);
    if (abs(currentRow - newRow) <= 1 && abs(currentColumn - newColumn) <= 1)
    {
        if (dest != nullptr)
        {
            if (dest->isWhite() != this->isWhite())
            {
                isCaptured = true;
                return true;
            }
            else
            {
                return false;
            }
        }
        return true; 
    }
    if (currentRow == newRow && abs(currentColumn - newColumn) == 2)
    {
        bool isKingSide = (newColumn > currentColumn);
        int rookColumn = isKingSide ? 7 : 0;
        int direction = isKingSide ? 1 : -1;

        if ((this->isWhite() && _whiteKingMoved) || (!this->isWhite() && _blackKingMoved))
            return false;

        Piece* rook = plateau->getPiece(currentRow, rookColumn);
        if (!rook || rook->getType() != "rook" /* || rook->hasMoved() à gérer aussi */)
            return false;

        for (int c = currentColumn + direction; c != rookColumn; c += direction)
        {
            if (plateau->getPiece(currentRow, c) != nullptr)
                return false;
        }

        return true;
    }

    return false;
}

std::string King::getType() const
{
	return "king";
}

Piece* King::clone() const
{
	return new King(*this);
}
