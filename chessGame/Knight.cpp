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
	if (abs(newRow - currentRow) == 2 && abs(newColumn - currentColumn) == 1) // V�rifie si le mouvement est en forme de L
	{
		Piece* dest = plateau->getPiece(newRow, newColumn); // V�rifie si la case de destination est vide ou occup�e par une pi�ce adverse
		if (dest == nullptr || dest->isWhite() != this->_isWhite) // V�rifie si la pi�ce de destination est de la m�me couleur
		{
			return true;
		}
	}
	else if (abs(newRow - currentRow) == 1 && abs(newColumn - currentColumn) == 2) // V�rifie si le mouvement est en forme de L
	{
		Piece* dest = plateau->getPiece(newRow, newColumn);
		if (dest == nullptr || dest->isWhite() != this->_isWhite)
		{
			return true;
		}
	}
	return false;
}

