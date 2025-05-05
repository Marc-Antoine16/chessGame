#include "Rook.h"
#include <vector>
#include "Plateau.h"
#include "Piece.h"


using namespace std;

Rook::Rook(bool isWhite, QString& imagePath) : Piece(isWhite, imagePath)
{
	_currentRow = 0;
	_currentColumn = 0;
	_isWhite = isWhite;
	_imagePath = imagePath;
	setImage(_imagePath);
}

Rook::Rook(int currentRow, int currentColumn, bool isWhite, QString& imagePath) : Piece(currentRow, currentColumn, isWhite, imagePath)
{
	_currentRow = currentRow;
	_currentColumn = currentColumn;
	_isWhite = isWhite;
	_imagePath = imagePath;
	setImage(_imagePath);
}

bool Rook::possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool isCaptured, Plateau *plateau) const
{
    if (currentRow == newRow)
    {
        int step = (newColumn > currentColumn) ? 1 : -1;
        for (int col = currentColumn + step; col != newColumn; col += step)
        {
            if (plateau->getPiece(currentRow, col) != nullptr)
                return false; // Il y a un obstacle
        }
	}
	else if (currentColumn == newColumn)
	{
		int step = (newRow > currentRow) ? 1 : -1;
		for (int row = currentRow + step; row != newRow; row += step)
		{
			if (plateau->getPiece(row, currentColumn) != nullptr)
			{
				return false; // Il y a un obstacle
			}	
		}
	}
    else
    {
        return false; // Ni horizontal ni vertical
    }

	Piece* dest = plateau->getPiece(newRow, newColumn);

	if (dest == nullptr || dest->isWhite() != this->_isWhite)
	{
		return true;
	}
		

	return false;
}

