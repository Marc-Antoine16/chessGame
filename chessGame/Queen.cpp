#include "Queen.h"
#include "Plateau.h"
#include "Piece.h"
#include <vector>

bool Queen::possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool& isCaptured, Plateau* plateau) const
{
    int dRow = newRow - currentRow;
    int dCol = newColumn - currentColumn;

    if (dRow != 0 && dCol != 0 && abs(dRow) != abs(dCol))
        return false;

    int stepRow = (dRow == 0) ? 0 : (dRow > 0 ? 1 : -1);
    int stepCol = (dCol == 0) ? 0 : (dCol > 0 ? 1 : -1);

    int r = currentRow + stepRow;
    int c = currentColumn + stepCol;

    while (r != newRow || c != newColumn)
    {
        if (plateau->isOccupied(r, c))
            return false; 

        r += stepRow;
        c += stepCol;
    }

    Piece* destPiece = plateau->getPiece(newRow, newColumn);

    if (destPiece == nullptr)
    {
        isCaptured = false;
        return true;
    }
    else if (destPiece->isWhite() != this->isWhite())
    {
        isCaptured = true;
        return true;
    }
    return false;
}
Queen::Queen(bool isWhite, QString& imagePath) : Piece(isWhite, imagePath)
{
	_deplacement = { { 1, 0 }, { -1, 0 },
	{ 0, 1 }, { 0, -1 },
	{ 1, 1 }, { -1, -1 },
	{ 1, -1 }, { -1, 1 } };
}

Queen::Queen(int currentRow, int currentColumn, bool isWhite, QString& imagePath) : Piece(currentRow, currentColumn, isWhite, imagePath)
{
	_deplacement = { { 1, 0 }, { -1, 0 },
	{ 0, 1 }, { 0, -1 },
	{ 1, 1 }, { -1, -1 },
	{ 1, -1 }, { -1, 1 } };
}


std::string Queen::getType() const
{
	return "queen";
}

Piece* Queen::clone() const
{
	return new Queen(*this);
}