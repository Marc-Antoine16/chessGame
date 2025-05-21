#pragma once
#include "Piece.h"
#include <vector>
#include <QString>

class Queen : public Piece
{
private:
	std::vector<std::pair<int, int>> _deplacement;
public:
	Queen(bool isWhite, QString& imagePath);
	Queen(int currentRow, int currentColumn, bool isWhite, QString& imagePath);
	std::string getType() const override;
	Piece* clone() const override;
	bool possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool &isCaptured, Plateau* plateau) const;
};