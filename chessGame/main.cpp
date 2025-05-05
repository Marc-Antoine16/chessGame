#include "chessGame.h"
#include <QtWidgets/QApplication>
#include "Echiquier.h"
#include "Plateau.h"
#include "Pawn.h"
#include "Plateau.h"
#include <fstream>
#include <QFile>
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"


int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	Plateau plateau;
	QString path = ":/chessGame/pawn_white.png";
	QString blackPath = ":/chessGame/pawn_black.png";
	QString WrookPath = ":/chessGame/white_rook.png";
	QString BrookPath = ":/chessGame/black_rook.png"; 
	QString blackBishopPath = ":/chessGame/black_bishop.png";
	QString whiteBishopPath = ":/chessGame/white_bishop.png";
	QString blackKnightPath = ":/chessGame/112-1127048_chess-knight-png-knight-chess-pieces-png-transparent.png";
	QString whiteKnightPath = ":/chessGame/455-4559527_knight-clipart-chess-piece-lichess-logo.png";


	for (int i = 0; i < 8; i++)
	{
		Pawn* pawn = new Pawn(true, path);
		plateau.placer(pawn, 6, i);
		Pawn* blackPawn = new Pawn(false, blackPath);
		plateau.placer(blackPawn, 1, i);
	}
	Rook* rook = new Rook(true, WrookPath);
	plateau.placer(rook, 7, 0);
	plateau.placer(rook, 7, 7);
	Rook* blackRook = new Rook(false, BrookPath);
	plateau.placer(blackRook, 0, 7);
	plateau.placer(blackRook, 0, 0);

	Bishop* bishop = new Bishop(true, whiteBishopPath);
	plateau.placer(bishop, 7, 2);
	plateau.placer(bishop, 7, 5);
	Bishop* blackBishop = new Bishop(false, blackBishopPath);
	plateau.placer(blackBishop, 0, 5);
	plateau.placer(blackBishop, 0, 2);

	Knight* Wknight = new Knight(true, whiteKnightPath);
	plateau.placer(Wknight, 7, 1);
	plateau.placer(Wknight, 7, 6);
	Knight* bKnight = new Knight(false, blackKnightPath);
	plateau.placer(bKnight, 0, 6);
	plateau.placer(bKnight, 0, 1);

	Echiquier* fenetre = new Echiquier(plateau);
	fenetre->updateBoard();
	fenetre->setWindowTitle("jeu d'echec");
	fenetre->show();
	return a.exec();
}
