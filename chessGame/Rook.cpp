
#include "Rook.h"
#include <vector>
#include "Plateau.h"



using namespace std;

bool Rook::possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool &isCaptured, Plateau* plateau) const
{
    if (currentRow != newRow && currentColumn != newColumn)
        return false;

    int rowStep = (newRow == currentRow) ? 0 : (newRow > currentRow ? 1 : -1);
    int colStep = (newColumn == currentColumn) ? 0 : (newColumn > currentColumn ? 1 : -1);

    for (int row = currentRow + rowStep, col = currentColumn + colStep; row != newRow || col != newColumn; row += rowStep, col += colStep)
    {
        if (plateau->getPiece(row, col) != nullptr)
            return false;
    }

    Piece* dest = plateau->getPiece(newRow, newColumn);
    if (dest == nullptr || dest->isWhite() != this->_isWhite)
    {
        if (dest != nullptr && dest->isWhite() != this->_isWhite)
        {
            isCaptured = true;
        }
        return true;
    }
    return false;
}
 


