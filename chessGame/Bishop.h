#pragma once
#include "Piece.h"
#include <vector>

class Bishop : public Piece
{
private:
	std::vector<int> _deplacement;

public:
	Bishop(bool isWhite, QString& imagePath) : Piece(isWhite, imagePath) { }
	Bishop(int currentRow, int currentColumn, bool isWhite, QString& imagePath) : Piece(currentRow, currentColumn, isWhite, imagePath) { }
	bool possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool isCaptured, Plateau* plateau) const;
};
