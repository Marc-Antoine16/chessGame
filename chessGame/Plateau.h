#pragma once
#include "Piece.h"
#include <vector>
#include <queue>

class Piece;
class Echiquier;
class Queen;

class Plateau
{
private:
	Piece* _grid[8][8];
	Echiquier* _echiquier;
	std::queue<std::vector<std::string>> _moveDone;
public:
	Plateau();
	Plateau(const Plateau& plateau);
	Piece* getPiece(int row, int column) const;
	void placer(Piece* piece, int row, int column);
	bool moveValid(int currentRow, int currentColumn, int newRow, int newColumn);
	void deplacer(int currentRow, int currentColumn, int newRow, int newColumn);
	bool isOccupied(int row, int column) const;
	std::queue<std::vector<std::string>> getMoveDone() const;
	bool inCheck(bool isWhite);
	bool checkMate(bool isWhite);
	void setEchiquier(Echiquier* echiquier);
	Piece* promote(Piece* pawn);
	void clear();
	std::vector<int> findKing(bool isWhite);
	void clearMoveDone();
};