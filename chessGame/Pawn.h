#pragma once
#include "Piece.h"
#include <vector>
#include "Plateau.h"

class Pawn : public Piece
{
private:
	std::vector<int> _deplacement;

public:
	Pawn(bool isWhite, QString& imagePath);
	Pawn(int currentRow, int currentColumn, bool isWhite, QString& imagePath);
	std::string getType() const override;
	Piece* clone() const override;
	bool possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool &isCaptured, Plateau* plateau) const;
};

