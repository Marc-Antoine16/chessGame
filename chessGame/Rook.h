#pragma once
#include "Piece.h"
#include <vector>

class Rook : public Piece
{
private:
	std::vector<std::pair<int, int>> _deplacement;

public:
	Rook(bool isWhite, QString& imagePath);
	Rook(int currentRow, int currentColumn, bool isWhite, QString& imagePath);
	std::string getType() const override;
	Piece* clone() const override;
	bool possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool &isCaptured, Plateau* plateau) const;
};