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
#include <queue>
#include <vector>
#include <fstream>
#include <QTimer>

class Echiquier;
class Plateau;

class GameManager : public QObject {
	Q_OBJECT
private:
	Plateau _plateau;
	Echiquier* _echiquier;
	std::list<Piece*> _piecesCapturees;
	bool _tourBlanc;
	std::map < QString, QString> _imagePath;
	QTimer* _timerB;
	QTimer* _timerN;
	int _tempsB;
	int _tempsN;
public:
	GameManager(int temps);
	void startGame();
	~GameManager();
	void onButtonClicked(int row, int column);
	void putInCsv(std::queue<std::vector<std::string>> moveDone);
	void endGame();
	void onTimeoutBlanc();
	void onTimeoutNoir();
};
