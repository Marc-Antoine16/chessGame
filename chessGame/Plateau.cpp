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



Piece* Plateau::getPiece(int row, int column) const
{
	return _grid[row][column];
}

void Plateau::placer(Piece* piece, int row, int column)
{
	_grid[row][column] = piece;
}

void Plateau::move(int currentRow, int currentColumn, int newRow, int newColumn)
{
	bool isCaptured = false;

	Piece* source = _grid[currentRow][currentColumn];
	Piece* target = _grid[newRow][newColumn];

	if (target != nullptr && source != nullptr)
	{
		if (source->isWhite() != target->isWhite())
		{
			isCaptured = true;
			//delete target; // Capture la pièce adverse
			target = nullptr;
		}

	}
	if (isCaptured)
	{
		if (_grid[currentRow][currentColumn]->possibleMove(currentRow, currentColumn, newRow, newColumn, isCaptured, this))
		{
			_grid[newRow][newColumn] = _grid[currentRow][currentColumn];
			_grid[currentRow][currentColumn] = nullptr;
			_grid[newRow][newColumn]->move(newRow, newColumn);
		}
	}
	else if (!isOccupied(newRow, newColumn))
	{
		if (_grid[currentRow][currentColumn]->possibleMove(currentRow, currentColumn, newRow, newColumn, isCaptured, this))
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