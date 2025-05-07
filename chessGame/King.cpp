#include "King.h"


bool King::possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool isCaptured, Plateau* plateau) const
{
    if (abs(currentRow - newRow) > 1 || abs(currentColumn - newColumn) > 1)
        return false;

    Piece* dest = plateau->getPiece(newRow, newColumn);

    if (dest != nullptr && dest->isWhite() != this->isWhite())
        return true;

    if (dest == nullptr)
        return true;

    return false;
}
