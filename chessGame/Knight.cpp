#include "Knight.h"


bool Knight::possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool isCaptured, Plateau* plateau) const
{
	if (abs(newRow - currentRow) == 2 && abs(newColumn - currentColumn) == 1)
	{
		Piece* dest = plateau->getPiece(newRow, newColumn);
		if (dest == nullptr || dest->isWhite() != this->_isWhite)
		{
			return true;
		}
	}
	else if (abs(newRow - currentRow) == 1 && abs(newColumn - currentColumn) == 2)
	{
		Piece* dest = plateau->getPiece(newRow, newColumn);
		if (dest == nullptr || dest->isWhite() != this->_isWhite)
		{
			return true;
		}
	}
	return false;
}

