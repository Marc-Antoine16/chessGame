#pragma once
#include "Echiquier.h"
#include "Pawn.h"
#include "Plateau.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include <list>


class GameManager {
private:
	Plateau _plateau;
	Echiquier* _echiquier;
	bool _tourBlanc;
	std::list<Piece*> _piecesCapturees;
public:
	GameManager();
	void startGame();
	~GameManager();
};
