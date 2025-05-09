#include "Bishop.h"


bool Bishop::possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool &isCaptured, Plateau* plateau) const
{
	if (abs(newRow - currentRow) == abs(newColumn - currentColumn)) 
	{
		int rowStep = (newRow > currentRow) ? 1 : -1;
		int colStep = (newColumn > currentColumn) ? 1 : -1;
		for (int row = currentRow + rowStep, col = currentColumn + colStep; row != newRow && col != newColumn; row += rowStep, col += colStep)
		{
			if (plateau->getPiece(row, col) != nullptr)
			{
				return false;
			}
		}
		Piece* dest = plateau->getPiece(newRow, newColumn);
		if (dest == nullptr || dest->isWhite() != this->_isWhite)
		{
			if (dest != nullptr && dest->isWhite() != this->_isWhite)
			{
				isCaptured = true;
			}
			return true;
		}
		return false;
	}
	

	return false;
}

