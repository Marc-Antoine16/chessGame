#include "Knight.h"

Knight::Knight(bool isWhite, QString& imagePath) : Piece(isWhite, imagePath)
{
	_currentRow = 0;
	_currentColumn = 0;
	_isWhite = isWhite;
	_imagePath = imagePath;
	setImage(_imagePath);
}

Knight::Knight(int currentRow, int currentColumn, bool isWhite, QString& imagePath) : Piece(currentRow, currentColumn, isWhite, imagePath)
{
	_currentRow = currentRow;
	_currentColumn = currentColumn;
	_isWhite = isWhite;
	_imagePath = imagePath;
	setImage(_imagePath);
}

bool Knight::possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool isCaptured, Plateau* plateau) const
{
	if (abs(newRow - currentRow) == 2 && abs(newColumn - currentColumn) == 1) // Vérifie si le mouvement est en forme de L
	{
		Piece* dest = plateau->getPiece(newRow, newColumn); // Vérifie si la case de destination est vide ou occupée par une pièce adverse
		if (dest == nullptr || dest->isWhite() != this->_isWhite) // Vérifie si la pièce de destination est de la même couleur
		{
			return true;
		}
	}
	else if (abs(newRow - currentRow) == 1 && abs(newColumn - currentColumn) == 2) // Vérifie si le mouvement est en forme de L
	{
		Piece* dest = plateau->getPiece(newRow, newColumn);
		if (dest == nullptr || dest->isWhite() != this->_isWhite)
		{
			return true;
		}
	}
	return false;
}

