#include "King.h"


bool King::possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool& isCaptured, Plateau* plateau) const
{

	Piece* dest = plateau->getPiece(newRow, newColumn);

	if (currentRow == newRow && abs(currentColumn - (newColumn)) == 2)
	{
		bool isKingSide = (currentColumn < newColumn);
		int rookColumn = isKingSide ? 7 : 0;
		int direction = isKingSide ? 1 : -1;

		if ((this->isWhite() && _whiteKingMoved) || (!this->isWhite() && _blackKingMoved))
			return false;

		Piece* rook = plateau->getPiece(currentRow, rookColumn);
		if (!rook || rook->getType() != "rook" /*||*/ /*rook->hasMoved()*/)
			return false;


		for (int c = currentColumn + direction; c != rookColumn; c += direction)
		{
			if (plateau->getPiece(currentRow, c) != nullptr)
				return false;
		}
		return true;
	}

	if (abs(currentRow - newRow) > 1 || abs(currentColumn - newColumn) > 1)
		return false;

	if (dest != nullptr && dest->isWhite() != this->isWhite())
	{
		isCaptured = true;
		return true;
	}

	if (dest == nullptr)
		return true;

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
