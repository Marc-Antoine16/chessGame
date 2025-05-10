#include "Knight.h"


bool Knight::possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool &isCaptured, Plateau* plateau) const
{
	if (abs(newRow - currentRow) == 2 && abs(newColumn - currentColumn) == 1)
	{
		Piece* dest = plateau->getPiece(newRow, newColumn);
		{
			Piece* dest = plateau->getPiece(newRow, newColumn);
			if (dest == nullptr) 
			{
				return true;
			}

			else if (dest->isWhite() != this->_isWhite) {
				isCaptured = true;
				return true;
			}
			return false;
		}
		return false;
	}
	else if (abs(newRow - currentRow) == 1 && abs(newColumn - currentColumn) == 2)
	{
		Piece* dest = plateau->getPiece(newRow, newColumn);
		if (dest == nullptr) {
			return true;
		}
		else if (dest->isWhite() != this->_isWhite) {
			isCaptured = true;
			return true;
		}
		return false;
	}
	return false;
}

std::string Knight::getType() const
{
	return "knight";
}

Piece* Knight::clone() const
{
	return new Knight(*this);
}