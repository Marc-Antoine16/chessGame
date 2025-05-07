#include "Queen.h"
#include "Plateau.h"
#include "Piece.h"
#include <vector>

bool Queen::possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool isCaptured, Plateau* plateau) const {
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
	} else if (currentRow != newRow && currentColumn != newColumn)
		return false;

	int rowStep = (newRow == currentRow) ? 0 : (newRow > currentRow ? 1 : -1);
	int colStep = (newColumn == currentColumn) ? 0 : (newColumn > currentColumn ? 1 : -1);

	for (int row = currentRow + rowStep, col = currentColumn + colStep; row != newRow || col != newColumn; row += rowStep, col += colStep)
	{
		if (plateau->getPiece(row, col) != nullptr)
			return false;
	}

	Piece* dest = plateau->getPiece(newRow, newColumn);
	return (dest == nullptr || dest->isWhite() != this->_isWhite);
}

