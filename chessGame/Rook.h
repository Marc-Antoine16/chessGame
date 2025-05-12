#pragma once
#include "Piece.h"
#include <vector>

class Piece;

class Rook : public Piece
{
private:
	std::vector<int> _deplacement;
	bool _whiteKingsideRookMoved = false;
	bool _whiteQueensideRookMoved = false;
	bool _blackKingsideRookMoved = false;
	bool _blackQueensideRookMoved = false;

public:
	Rook(bool isWhite, QString& imagePath) : Piece(isWhite, imagePath) { }
	Rook(int currentRow, int currentColumn, bool isWhite, QString& imagePath) : Piece(currentRow, currentColumn, isWhite, imagePath) { }
	bool possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool &isCaptured, Plateau* plateau) const;
	std::string getType() const override { return "rook"; }
};