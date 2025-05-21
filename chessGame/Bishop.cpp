#include "Bishop.h"

Bishop::Bishop(bool isWhite, QString& imagePath) : Piece(isWhite, imagePath)
{
	_deplacement = { {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
}

Bishop::Bishop(int currentRow, int currentColumn, bool isWhite, QString& imagePath) : Piece(currentRow, currentColumn, isWhite, imagePath)
{
	_deplacement = { {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
}

bool Bishop::possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool& isCaptured, Plateau* plateau) const
{
    for (auto direction : _deplacement)
    {
        int i = currentRow + direction.first;
        int j = currentColumn + direction.second;

        while (i >= 0 && i < 8 && j >= 0 && j < 8)
        {
            if (i == newRow && j == newColumn)
            {
                Piece* target = plateau->getPiece(i, j);

                if (target == nullptr)
                {
                    isCaptured = false;
                    return true;
                }
                else if (target->isWhite() != this->isWhite())
                {
                    isCaptured = true;
                    return true;
                }
                else
                {
                    return false;
                }
            }

            if (plateau->isOccupied(i, j))
                break;

            i += direction.first;
            j += direction.second;
        }
    }

    return false;
}

std::string Bishop::getType() const
{
	return "bishop";
}

Piece* Bishop::clone() const 
{
	return new Bishop(*this);
}
