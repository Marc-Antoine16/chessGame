#pragma once
#include "Piece.h"
#include <vector>

class Knight : public Piece
{
	std::vector<std::pair<int, int>> _deplacement;
public:
	Knight(bool isWhite, QString& imagePath);
	Knight(int currentRow, int currentColumn, bool isWhite, QString& imagePath);
	std::string getType() const override;
	Piece* clone() const override;
	bool possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool &isCaptured, Plateau* plateau) const;
};
