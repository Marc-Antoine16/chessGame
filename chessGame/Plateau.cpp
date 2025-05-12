#include "Plateau.h"
#include "Echiquier.h"
#include <QIcon>


Plateau::Plateau()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
	
			//_grid[i][j] = nullptr;
		}
	}
}




Plateau::Plateau(Echiquier* echiquier)
{
	_echiquier = echiquier;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			_grid[i][j] = nullptr;
		}
	}

}

Piece* Plateau::getPiece(int row, int column) const
{
	return _grid[row][column];
}



void Plateau::placer(Piece* piece, int row, int column)
{
	_grid[row][column] = piece;
}

bool Plateau::moveValid(int currentRow, int currentColumn, int newRow, int newColumn, Plateau* plateau)
{
	bool isCaptured = false;

	Piece* source = _grid[currentRow][currentColumn];
	Piece* target = _grid[newRow][newColumn];

	
	if (target != nullptr && source != nullptr)
	{
		if (source->isWhite() != target->isWhite())
		{
			isCaptured = true;

			target = nullptr;
		}
		else return false;
	}
	if (isCaptured)
	{
		if (_grid[currentRow][currentColumn]->possibleMove(currentRow, currentColumn, newRow, newColumn, isCaptured, this))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (!isOccupied(newRow, newColumn))
	{
		if (_grid[currentRow][currentColumn]->possibleMove(currentRow, currentColumn, newRow, newColumn, isCaptured, this))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

void Plateau::deplacer(int currentRow, int currentColumn, int newRow, int newColumn)
{

	Piece* piece = _grid[currentRow][currentColumn];


	if (piece->getType() == "king" && abs(newColumn - currentColumn) == 2) //la tour se deplace mais pas son image...
	{
		int rookColumn = (newColumn > currentColumn) ? 7 : 0;
		Piece* rook = _grid[currentRow][rookColumn];

		_grid[currentRow][rookColumn] = nullptr;
		if (rook)
		{
			
			if (newColumn > currentColumn)
			{
				_grid[currentRow][currentColumn + 1] = rook;
				rook->move(currentRow, currentColumn + 1);

				
				/*_echiquier->updateBoard(currentRow, rookColumn);*/
				
			}
			else
			{
				_grid[currentRow][currentColumn - 1] = rook;
				rook->move(currentRow, currentColumn - 1);

				
				/*_echiquier->updateBoard(currentRow, rookColumn);*/

				
			}
		}
	}

	_grid[newRow][newColumn] = piece;
	_grid[currentRow][currentColumn] = nullptr;
	if (piece)
	{
		piece->move(newRow, newColumn);
		piece->setMoved(true);
	}
		
}

bool Plateau::isOccupied(int row, int column) const
{

	if (_grid[row][column] != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}



