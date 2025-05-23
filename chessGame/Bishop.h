#pragma once
#include "Piece.h"
#include <vector>

class Bishop : public Piece
{
private:
	std::vector<std::pair<int,int>> _deplacement;

public:
	Bishop(bool isWhite, QString& imagePath);
	Bishop(int currentRow, int currentColumn, bool isWhite, QString& imagePath);
	bool possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool &isCaptured, Plateau* plateau) const;
	std::string getType() const override;
	Piece* clone() const override;
};
