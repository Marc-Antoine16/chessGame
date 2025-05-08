#pragma once

#include "piece.h"

class King : public Piece
{
public:
	King(bool isWhite, QString& imagePath) : Piece(isWhite, imagePath) { }
	King(int currentRow, int currentColumn, bool isWhite, QString& imagePath) : Piece(currentRow, currentColumn, isWhite, imagePath) { }
	bool possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool &isCaptured, Plateau* plateau) const;
};