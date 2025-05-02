#include "chessGame.h"
#include <QtWidgets/QApplication>
#include "Echiquier.h"
#include "Plateau.h"
#include "Pawn.h"
#include "Plateau.h"
#include <fstream>
#include <QFile>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	Plateau plateau;
	QString path = ":/chessGame/pawn_white.png";
	QString blackPath = ":/chessGame/pawn_black.png";
	for (int i = 0; i < 8; i++)
	{
		Pawn* pawn = new Pawn(true, path);
		plateau.placer(pawn, 6, i);
		Pawn* blackPawn = new Pawn(false, blackPath);
		plateau.placer(blackPawn, 1, i);
	}
	Echiquier* fenetre = new Echiquier(plateau);
	fenetre->updateBoard();
	fenetre->setWindowTitle("jeu d'echec");
	fenetre->show();
	return a.exec();
}
