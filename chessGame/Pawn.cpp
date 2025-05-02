#include "Pawn.h"

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

bool Pawn::possibleMove(int currentRow, int currentColumn, int newRow, int newColumn) const
{
	if (currentColumn != newColumn)
		return false;

	int direction = _isWhite ? -1 : 1;
	int startRow = _isWhite ? 6 : 1;
	if (currentRow == startRow && newRow == currentRow + 2 * direction)
	{
		return true;
	}
	else if (newRow == currentRow + direction)
	{
		return true;
	}
	else
		return false;
}