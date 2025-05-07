#pragma once
#include "Piece.h"
#include <vector>

class Queen : public Piece
{
private:
	std::vector<int> _deplacement;
public:
	Queen(bool isWhite, QString& imagePath) : Piece(isWhite, imagePath) {}
	Queen(int currentRow, int currentColumn, bool isWhite, QString& imagePath) : Piece(currentRow, currentColumn, isWhite, imagePath) {}
	bool possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool isCaptured, Plateau* plateau) const;
};
