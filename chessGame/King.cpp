#include "King.h"


bool King::possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool &isCaptured, Plateau* plateau)  const
{
    

    Piece* dest = plateau->getPiece(newRow, newColumn);
	
	if (currentRow == (newRow) && abs(currentColumn - (newColumn)) == 2)
	{
		bool isKingside = newColumn > currentColumn;
		int rookColumn = isKingside ? 7 : 0;
		int direction = isKingside ? 1 : -1;

		if ((this->isWhite() && _whiteKingMoved) || (!this->isWhite() && _blackKingMoved))
			//Vérifie que ni le roi ni la tour n'ont bougé
			return false;
		
		Piece* rook = plateau->getPiece(currentRow, rookColumn);
		if (!rook || rook->getType() != "rook" || rook->hasMoved())
			return false;

		for (int c = currentColumn + direction; c != rookColumn; c += direction)
		{
			if (plateau->getPiece(currentRow, c))
				return false;
		}
		///*for (int c = currentColumn; c != newColumn + direction; c += direction) {
		//	if (plateau->isSquareAttacked(currentRow, c, !this->isWhite()))  //Exemple pour quand on va avoir les echec 
		//		return false;*/
		//}

		/*if (this->isWhite())
			_whiteKingMoved = true;  //pas bon car passe 2fois une fois pour regarder si valid(highlight) et une fois pour le deplacement
		else
			_blackKingMoved = true;*/

		return true;

	}

	if (abs(currentRow - newRow) > 1 || abs(currentColumn - newColumn) > 1)
		return false;

	if (dest != nullptr && dest->isWhite() != this->isWhite())
	{
		isCaptured = true;
		return true;

	/*	if (!_blackKingMoved && !_isWhite)
		{
			_blackKingMoved = true;
		}
		else if (!_whiteKingMoved && _isWhite)
		{
			_whiteKingMoved = true;
		}*/
	}


    if (dest == nullptr)
    {
	/*	if (!_blackKingMoved && !_isWhite)
		{
			_blackKingMoved = true;
		}
		else if (!_whiteKingMoved && _isWhite)
		{
			_whiteKingMoved = true;
		}*/
		return true;
    }
        
	
	return false;
}




