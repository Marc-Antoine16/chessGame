#include "GameManager.h"

GameManager::GameManager()
{
	_tourBlanc = true;

	_imagePath["WPawn"] = ":/chessGame/pawn_white.png";
	_imagePath["BPawn"] = ":/chessGame/pawn_black.png";
	_imagePath["WRook"] = ":/chessGame/white_rook.png";
	_imagePath["BRook"] = ":/chessGame/black_rook.png";
	_imagePath["WBishop"] = ":/chessGame/white_bishop.png";
	_imagePath["BBishop"] = ":/chessGame/black_bishop.png";
	_imagePath["WKnight"] = ":/chessGame/white_knight.png";
	_imagePath["BKnight"] = ":/chessGame/black_knight.png";
	_imagePath["WQueen"] = ":/chessGame/white_queen.png";
	_imagePath["BQueen"] = ":/chessGame/black_queen.png";
	_imagePath["WKing"] = ":/chessGame/PierLucLeGoat.png";
	_imagePath["BKing"] = ":/chessGame/black_king.png";


	for (int i = 0; i < 8; i++)
	{
		Pawn* pawn = new Pawn(true, _imagePath["WPawn"]);
		_piecesCapturees.push_back(pawn);
		_plateau.placer(pawn, 6, i);
		Pawn* blackPawn = new Pawn(false, _imagePath["BPawn"]);
		_piecesCapturees.push_back(blackPawn);
		_plateau.placer(blackPawn, 1, i);
	}

	Rook* rook = new Rook(true, _imagePath["WRook"]);
	_piecesCapturees.push_back(rook);
	_plateau.placer(rook, 7, 0);
	_plateau.placer(rook, 7, 7);
	Rook* blackRook = new Rook(false, _imagePath["BRook"]);
	_piecesCapturees.push_back(blackRook);
	_plateau.placer(blackRook, 0, 7);
	_plateau.placer(blackRook, 0, 0);

	Bishop* bishop = new Bishop(true, _imagePath["WBishop"]);
	_piecesCapturees.push_back(bishop);
	_plateau.placer(bishop, 7, 2);
	_plateau.placer(bishop, 7, 5);
	Bishop* blackBishop = new Bishop(false, _imagePath["BBishop"]);
	_piecesCapturees.push_back(blackBishop);
	_plateau.placer(blackBishop, 0, 5);
	_plateau.placer(blackBishop, 0, 2);

	Knight* Wknight = new Knight(true, _imagePath["WKnight"]);
	_piecesCapturees.push_back(Wknight);
	_plateau.placer(Wknight, 7, 1);
	_plateau.placer(Wknight, 7, 6);
	Knight* bKnight = new Knight(false, _imagePath["BKnight"]);
	_piecesCapturees.push_back(bKnight);
	_plateau.placer(bKnight, 0, 6);
	_plateau.placer(bKnight, 0, 1);

	King* WKing = new King(true, _imagePath["WKing"]);
	_piecesCapturees.push_back(WKing);
	_plateau.placer(WKing, 7, 4);

	King* BKing = new King(false, _imagePath["BKing"]);
	_piecesCapturees.push_back(BKing);
	_plateau.placer(BKing, 0, 4);

	Queen* WQueen = new Queen(true, _imagePath["WQueen"]);
	_piecesCapturees.push_back(WQueen);
	_plateau.placer(WQueen, 7, 3);

	Queen* BQueen = new Queen(false, _imagePath["BQueen"]);
	_piecesCapturees.push_back(BQueen);
	_plateau.placer(BQueen, 0, 3);
}

void GameManager::startGame() {
	_echiquier = new Echiquier(_plateau, this);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
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
			_echiquier->higlightSquare(row, column);
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

void GameManager::putInCsv(std::queue<std::vector<std::string>> moveDone)
{
	std::ofstream fichierE("data.csv");
	std::string separateur = " , ";

	if (fichierE)
	{
		while (!moveDone.empty())
		{
			std::vector<std::string> move = moveDone.front();
			moveDone.pop();
			for (size_t i = 0; i < move.size(); i++)
			{
				fichierE << move[i];
				if (i != move.size() - 1)
					fichierE << separateur;
			}
			fichierE << std::endl;
		}
	}
	else
	{
		std::cerr << "Erreur d'ouverture du fichier" << std::endl;
	}
}

void GameManager::endGame()
{
	putInCsv(_plateau.getMoveDone());
}
