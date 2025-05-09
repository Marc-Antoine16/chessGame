#pragma once
#include "Echiquier.h"
#include "Pawn.h"
#include "Plateau.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "King.h"
#include "Queen.h"
#include <list>
#include <map>

class Echiquier;
class Plateau;

class GameManager {
private:
	Plateau _plateau;
	Echiquier* _echiquier;
	std::list<Piece*> _piecesCapturees;
	bool _tourBlanc;
	std::map < QString, QString> _imagePath;
public:
	GameManager();
	void startGame();
	~GameManager();
	void onButtonClicked(int row, int column);
};
