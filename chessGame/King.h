#pragma once

#include "piece.h"

class King : public Piece
{
private:
	 bool _whiteKingMoved = false;
	 bool _blackKingMoved = false;
	
public:
	King(bool isWhite, QString& imagePath) : Piece(isWhite, imagePath) { }
	King(int currentRow, int currentColumn, bool isWhite, QString& imagePath) : Piece(currentRow, currentColumn, isWhite, imagePath) { }
	bool possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool &isCaptured, Plateau* plateau) const;
	std::string getType() const override;
	Piece* clone() const override;
};