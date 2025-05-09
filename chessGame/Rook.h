#pragma once
#include "Piece.h"
#include <vector>

class Rook : public Piece
{
private:
	std::vector<int> _deplacement;

public:
	Rook(bool isWhite, QString& imagePath) : Piece(isWhite, imagePath) { }
	Rook(int currentRow, int currentColumn, bool isWhite, QString& imagePath) : Piece(currentRow, currentColumn, isWhite, imagePath) { }
	bool possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool &isCaptured, Plateau* plateau) const;
};