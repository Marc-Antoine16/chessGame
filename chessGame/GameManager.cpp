#include "GameManager.h"

GameManager::GameManager() 
{
	_tourBlanc = true;
	
	QString path = ":/chessGame/pawn_white.png";
	QString blackPath = ":/chessGame/pawn_black.png";
	QString WrookPath = ":/chessGame/white_rook.png";
	QString BrookPath = ":/chessGame/black_rook.png";
	QString blackBishopPath = ":/chessGame/black_bishop.png";
	QString whiteBishopPath = ":/chessGame/white_bishop.png";
	QString blackKnightPath = ":/chessGame/black_knight.png";
	QString whiteKnightPath = ":/chessGame/white_knight.png";
	QString WkingPath = ":/chessGame/PierLucLeGoat.png";
	QString BkingPath = ":/chessGame/BKing.png";
	QString BQueenPath = ":/chessGame/BQueen.png";
	QString WQueenPath = ":/chessGame/WQueen.png";

	for (int i = 0; i < 8; i++)
	{
		Pawn* pawn = new Pawn(true, path);
		_piecesCapturees.push_back(pawn);
		_plateau.placer(pawn, 6, i);
		Pawn* blackPawn = new Pawn(false, blackPath);
		_piecesCapturees.push_back(blackPawn);
		_plateau.placer(blackPawn, 1, i);
	}

	Rook* rook = new Rook(true, WrookPath);
	_piecesCapturees.push_back(rook);
	_plateau.placer(rook, 7, 0);
	_plateau.placer(rook, 7, 7);
	Rook* blackRook = new Rook(false, BrookPath);
	_piecesCapturees.push_back(blackRook);
	_plateau.placer(blackRook, 0, 7);
	_plateau.placer(blackRook, 0, 0);

	Bishop* bishop = new Bishop(true, whiteBishopPath);
	_piecesCapturees.push_back(bishop);
	_plateau.placer(bishop, 7, 2);
	_plateau.placer(bishop, 7, 5);
	Bishop* blackBishop = new Bishop(false, blackBishopPath);
	_piecesCapturees.push_back(blackBishop);
	_plateau.placer(blackBishop, 0, 5);
	_plateau.placer(blackBishop, 0, 2);

	Knight* Wknight = new Knight(true, whiteKnightPath);
	_piecesCapturees.push_back(Wknight);
	_plateau.placer(Wknight, 7, 1);
	_plateau.placer(Wknight, 7, 6);
	Knight* bKnight = new Knight(false, blackKnightPath);
	_piecesCapturees.push_back(bKnight);
	_plateau.placer(bKnight, 0, 6);
	_plateau.placer(bKnight, 0, 1);

	King* WKing = new King(true, WkingPath);
	_piecesCapturees.push_back(WKing);
	_plateau.placer(WKing, 7, 4);

	King* BKing = new King(false, BkingPath);
	_piecesCapturees.push_back(BKing);
	_plateau.placer(BKing, 0, 4);

	Queen* WQueen = new Queen(true, WQueenPath);
	_piecesCapturees.push_back(WQueen);
	_plateau.placer(WQueen, 7, 3);

	Queen* BQueen = new Queen(false, BQueenPath);
	_piecesCapturees.push_back(BQueen);
	_plateau.placer(BQueen, 0, 3);
	
}

void GameManager::startGame() {
	_echiquier = new Echiquier(_plateau, this);
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			_echiquier->updateBoard(i, j);
		}
	}
	_echiquier->setWindowTitle("jeu d'echec");
	_echiquier->show();
}

GameManager::~GameManager() {
	for (auto it : _piecesCapturees) {
		delete it;
	}
	delete _echiquier;
}

void GameManager::onButtonClicked(int row, int column)
{
	static int sourceRow = -1, sourceColumn = -1;

	if (sourceRow == -1 && sourceColumn == -1)
	{
		Piece* piece = _plateau.getPiece(row, column);

		if (piece != nullptr && piece->isWhite() == _tourBlanc)
		{
			sourceRow = row;
			sourceColumn = column;
		}
	}
	else
	{
		if (_plateau.moveValid(sourceRow, sourceColumn, row, column))
		{
			_plateau.deplacer(sourceRow, sourceColumn, row, column);

			_tourBlanc = !_tourBlanc;
			_echiquier->setTourLabel(_tourBlanc ? "Tour des blancs" : "Tour des noirs");
			_echiquier->updateBoard(sourceRow, sourceColumn);
			_echiquier->updateBoard(row, column);
		}
		sourceRow = -1;
		sourceColumn = -1;
	}
}