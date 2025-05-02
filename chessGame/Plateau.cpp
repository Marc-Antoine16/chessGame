#include "Plateau.h"


Plateau::Plateau()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			_grid[i][j] = nullptr;
		}
	}
}

Piece* Plateau::getPiece(int row, int column)
{
	return _grid[row][column];
}

void Plateau::placer(Piece* piece, int row, int column)
{
	_grid[row][column] = piece;
}

void Plateau::move(int currentRow, int currentColumn, int newRow, int newColumn)
{
	if (!isOccupied(newRow, newColumn))
	{
		if(_grid[currentRow][currentColumn]->possibleMove(currentRow, currentColumn, newRow, newColumn)) 
		{
			_grid[newRow][newColumn] = _grid[currentRow][currentColumn];
			_grid[currentRow][currentColumn] = nullptr;
			_grid[newRow][newColumn]->move(newRow, newColumn);
		}
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
