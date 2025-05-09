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
	std::vector<std::string> info;
	info.push_back("Type");
	info.push_back("isWhite");
	info.push_back("CurrentRow");
	info.push_back("CurrentColumn");
	info.push_back("NewRow");
	info.push_back("NewColumn");

	_moveDone.push(info);
}



Piece* Plateau::getPiece(int row, int column) const
{
	return _grid[row][column];
}

void Plateau::placer(Piece* piece, int row, int column)
{
	_grid[row][column] = piece;
}

bool Plateau::moveValid(int currentRow, int currentColumn, int newRow, int newColumn)
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
	_grid[newRow][newColumn] = piece;
	_grid[currentRow][currentColumn] = nullptr;
	if (piece)
	{
		piece->move(newRow, newColumn);
		std::vector<std::string> info;
		info.push_back(piece->getType());
		info.push_back(piece->isWhite() ? "true" : "false");
		info.push_back(std::to_string(currentRow));
		info.push_back(std::to_string(currentColumn));
		info.push_back(std::to_string(newRow));
		info.push_back(std::to_string(newColumn));

		_moveDone.push(info);
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