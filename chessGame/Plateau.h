#pragma once
#include "Piece.h"
#include <vector>

class Piece; // Forward declaration of Piece class sinon erreur

class Plateau 
{
private:
	Piece* _grid[8][8];
	
public:
	Plateau();
	
	Piece* getPiece(int row, int column) const;
	void placer(Piece* piece, int row, int column);
	void move(int currentRow, int currentColumn, int newRow, int newColumn);
	bool isOccupied(int row, int column) const;
};