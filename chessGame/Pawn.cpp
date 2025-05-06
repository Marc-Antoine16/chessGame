#include "Pawn.h"
#include "Plateau.h"

Pawn::Pawn(bool isWhite, QString& imagePath) : Piece(isWhite, imagePath)
{
	if (isWhite)
		_deplacement.push_back(_currentRow - 1);
	else
		_deplacement.push_back(_currentRow + 1);

}

Pawn::Pawn(int currentRow, int currentColumn, bool isWhite, QString& imagePath) : Piece(currentRow, currentColumn, isWhite, imagePath)
{
	if (isWhite)
	{
		_deplacement.push_back(currentRow - 1);
		_deplacement.push_back(currentRow - 2);
	}
	else
	{
		_deplacement.push_back(currentRow + 1);
		_deplacement.push_back(currentRow + 2);
	}
}

bool Pawn::possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool isCaptured, Plateau* plateau) const
{
	int direction = _isWhite ? -1 : 1;


	if (!_isCaptured && newColumn == currentColumn && newRow == currentRow + direction)
	{
		return plateau->getPiece(newRow, newColumn) == nullptr;
	}
	if (!_isCaptured && newColumn == currentColumn && currentRow == (_isWhite ? 6 : 1) && newRow == currentRow + (2 * direction))
	{

		return true;
	}
	if (isCaptured && newColumn != currentColumn && newRow == abs(currentRow + direction) && currentColumn != currentColumn + direction)
	{
		return true;
	}

	return false;
}