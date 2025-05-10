#pragma once
#include "Piece.h"
#include <vector>

class Knight : public Piece
{
private:
	std::vector<int> _deplacement;

public:
	Knight(bool isWhite, QString& imagePath) : Piece(isWhite, imagePath) { }
	Knight(int currentRow, int currentColumn, bool isWhite, QString& imagePath) : Piece(currentRow, currentColumn, isWhite, imagePath) { }
	std::string getType() const override;
	Piece* clone() const override;
	bool possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool &isCaptured, Plateau* plateau) const;
};
