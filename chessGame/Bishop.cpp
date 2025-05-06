#include "Bishop.h"

Bishop::Bishop(bool isWhite, QString& imagePath) : Piece(isWhite, imagePath)
{
	_currentRow = 0;
	_currentColumn = 0;
	_isWhite = isWhite;
	_imagePath = imagePath;
	setImage(_imagePath);
}

Bishop::Bishop(int currentRow, int currentColumn, bool isWhite, QString& imagePath) : Piece(currentRow, currentColumn, isWhite, imagePath)
{
	_currentRow = currentRow;
	_currentColumn = currentColumn;
	_isWhite = isWhite;
	_imagePath = imagePath;
	setImage(_imagePath);
}

bool Bishop::possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool isCaptured, Plateau* plateau) const
{
	if (abs(newRow - currentRow) == abs(newColumn - currentColumn)) // Vérifie si le mouvement est diagonal
	{
		// Vérifie s'il y a des obstacles sur la diagonale
		int rowStep = (newRow > currentRow) ? 1 : -1;
		int colStep = (newColumn > currentColumn) ? 1 : -1;
		for (int row = currentRow + rowStep, col = currentColumn + colStep; row != newRow && col != newColumn; row += rowStep, col += colStep)
		{
			if (plateau->getPiece(row, col) != nullptr)
			{
				return false; // Il y a un obstacle
			}
		}
		Piece* dest = plateau->getPiece(newRow, newColumn);
		if (dest == nullptr || dest->isWhite() != this->_isWhite)
		{
			return true;
		}
		return false;
	}
	

	return false;
}

