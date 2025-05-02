#pragma once
#include "Piece.h"
#include <vector>

class Pawn : public Piece
{
private:
	std::vector<int> _deplacement;
public:
	Pawn(bool isWhite, QString& imagePath);
	Pawn(int currentRow, int currentColumn, bool isWhite, QString& imagePath);
	bool possibleMove(int currentRow, int currentColumn, int newRow, int newColumn) const;
};
