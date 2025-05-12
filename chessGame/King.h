#pragma once

#include "Piece.h"

class Piece;

class King : public Piece
{
private:
	mutable bool _blackKingMoved = false; //le mutable est pour permettre de modifier la valeur de ces variables dans une fonction const
	mutable bool _whiteKingMoved = false;
public:
	King(bool isWhite, QString& imagePath) : Piece(isWhite, imagePath) {}
	King(int currentRow, int currentColumn, bool isWhite, QString& imagePath) : Piece(currentRow, currentColumn, isWhite, imagePath) {}
	bool possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool& isCaptured, Plateau* plateau) const;
	std::string getType() const override { return "king"; }
	bool whiteKingMoved() const { return _whiteKingMoved; }
	bool blackKingMoved() const { return _blackKingMoved; }
};