#include "Plateau.h"
#include "Echiquier.h"
#include "Queen.h"

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

Plateau::Plateau(const Plateau& plateau)
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (plateau._grid[i][j] != nullptr)
			{
				_grid[i][j] = plateau._grid[i][j]->clone();
			}
			else
			{
				_grid[i][j] = nullptr;
			}
		}
	}
	_moveDone = plateau._moveDone;
	_echiquier = plateau._echiquier;
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
	if (!source)
		return false;

	Piece* target = _grid[newRow][newColumn];

	if (target != nullptr)
	{
		if (source->isWhite() != target->isWhite())
		{
			isCaptured = true;
		}
		else
		{
			return false;
		}
	}
	return source->possibleMove(currentRow, currentColumn, newRow, newColumn, isCaptured, this);
}

void Plateau::deplacer(int currentRow, int currentColumn, int newRow, int newColumn)
{
	Piece* piece = _grid[currentRow][currentColumn];

	if (!piece)
		return;

	if (piece->getType() == "pawn" && newRow == (piece->isWhite() ? 0 : 7))
	{
		_grid[newRow][newColumn] = promote(piece);
		piece = _grid[newRow][newColumn];
		_grid[currentRow][currentColumn] = nullptr;
		_grid[newRow][newColumn]->move(newRow, newColumn);
	}

	else if (piece->getType() == "king" && abs(newColumn - currentColumn) == 2)
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

				_echiquier->updateBoard(currentRow, rookColumn);
				_echiquier->updateBoard(currentRow, currentColumn + 1);
			}
			else
			{
				_grid[currentRow][currentColumn - 1] = rook;
				rook->move(currentRow,currentColumn-1);

				_echiquier->updateBoard(currentRow, rookColumn);
				_echiquier->updateBoard(currentRow, currentColumn - 1);
			}	
		}


	}

	_grid[newRow][newColumn] = piece;
	_grid[currentRow][currentColumn] = nullptr;
	if (piece)
	{
		piece->move(newRow, newColumn);
		std::vector<std::string> info;
		info.push_back(piece->getType());
		info.push_back(piece->isWhite() ? "blanc" : "noir");
		info.push_back(std::to_string(currentRow + 1));
		info.push_back(std::to_string(currentColumn + 1));
		info.push_back(std::to_string(newRow + 1));
		info.push_back(std::to_string(newColumn + 1));

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

std::queue<std::vector<std::string>> Plateau::getMoveDone() const
{
	return _moveDone;
}

bool Plateau::inCheck(bool isWhite)
{
	int kingRow = findKing(isWhite)[0], kingColumn = findKing(isWhite)[1];
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Piece* piece = _grid[i][j];
			if (piece != nullptr && piece->isWhite() != isWhite)
			{
				bool isCaptured = true;
				if (piece->possibleMove(i, j, kingRow, kingColumn, isCaptured, this))
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool Plateau::checkMate(bool isWhite)
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			Piece* piece = _grid[i][j];
			if (piece != nullptr && piece->isWhite() == isWhite)
			{
				for (int x = 0; x < 8; ++x)
				{
					for (int y = 0; y < 8; ++y)
					{
						bool isCaptured = (_grid[x][y] != nullptr && _grid[x][y]->isWhite() != isWhite);
						if (piece->possibleMove(i, j, x, y, isCaptured, this))
						{
							Plateau copy = *this;
							copy.deplacer(i, j, x, y);
							if (!copy.inCheck(isWhite))
							{
								return false;
							}
						}
					}
				}
			}
		}
	}

	return true;
}

void Plateau::setEchiquier(Echiquier* echiquier)
{
	_echiquier = echiquier;
}

Piece* Plateau::promote(Piece* pawn) {
	bool isWhite = pawn->isWhite();
	delete pawn;
	QString imagePath = isWhite ? ":/chessGame/white_queen.png" : ":/chessGame/black_queen.png";
	return new Queen(isWhite, imagePath);
}

void Plateau::clear()
{
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) 
		{
			_grid[i][j] = nullptr;
		}
	}
}

std::vector<int> Plateau::findKing(bool isWhite)
{
	std::vector<int> kingPosition;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Piece* piece = _grid[i][j];
			if (piece != nullptr && piece->getType() == "king" && piece->isWhite() == isWhite)
			{
				kingPosition.push_back(i);
				kingPosition.push_back(j);
				return kingPosition;
			}
		}
	}
	return kingPosition;
}

void Plateau::clearMoveDone()
{
	while (!_moveDone.empty())
	{
		_moveDone.pop();
	}
}
