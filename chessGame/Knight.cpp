#include "Knight.h"


bool Knight::possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool& isCaptured, Plateau* plateau) const
{
    int deltaRow = newRow - currentRow;
    int deltaCol = newColumn - currentColumn;

    for (const auto& move : _deplacement) {
        if (deltaRow == move.first && deltaCol == move.second) {
            Piece* dest = plateau->getPiece(newRow, newColumn);
            if (dest == nullptr) {
                return true;
            }
            else if (dest->isWhite() != this->_isWhite) {
                isCaptured = true;
                return true;
            }
            else {
                return false;
            }
        }
    }

    return false;
}

Knight::Knight(bool isWhite, QString& imagePath) : Piece(isWhite, imagePath)
{
	_deplacement = { { 2, 1 }, { 1, 2 }, { -1, 2 }, { -2, 1 }, { -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 } };
}

Knight::Knight(int currentRow, int currentColumn, bool isWhite, QString& imagePath) : Piece(currentRow, currentColumn, isWhite, imagePath)
{
    _deplacement = { { 2, 1 }, { 1, 2 }, { -1, 2 }, { -2, 1 }, { -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 } };
}

std::string Knight::getType() const
{
	return "knight";
}

Piece* Knight::clone() const
{
	return new Knight(*this);
}