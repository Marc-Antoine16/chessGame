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
	if(currentColumn == newColumn)
	{
		if (_isWhite == true)
		{
			if (currentRow == 6)
			{
				if (newRow == currentRow - 2 || newRow == currentRow - 1)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			if (newRow == currentRow - 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (currentRow == 1)
			{
				if (newRow == currentRow + 2 || newRow == currentRow + 1)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			if (newRow == currentRow + 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}