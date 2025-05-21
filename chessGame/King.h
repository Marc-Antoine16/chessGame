#pragma once
#include <vector>
#include "piece.h"

class King : public Piece
{
private:
	bool _whiteKingMoved = false;
	bool _blackKingMoved = false;
	std::vector < std::pair<int, int>> _deplacement;
public:
	King(bool isWhite, QString& imagePath);
	King(int currentRow, int currentColumn, bool isWhite, QString& imagePath);
	bool possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool &isCaptured, Plateau* plateau) const;
	std::string getType() const override;
	Piece* clone() const override;
};