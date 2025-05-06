#include "Echiquier.h"
#include <QGridLayout>
#include <QIcon>

using namespace std;

Echiquier::Echiquier(Plateau& plateau) : _plateau(plateau)
{
	_tourBlanc = true;
	QGridLayout* layout = new QGridLayout(this);
	layout->setSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);
	int squareSize = 90;

	for (int i = 0; i < 8; i++)
	{
		vector<QPushButton*> row;
		for (int j = 0; j < 8; j++)
		{
			QPushButton* bouton = new QPushButton(this);
			bouton->setFixedSize(squareSize, squareSize);

			connect(bouton, &QPushButton::clicked, this, [=]()
				{
					onButtonClicked(i, j);
				});

			QString couleur = ((i + j) % 2 == 0) ? "rgb(210, 180, 140)" : "rgb(101, 67, 33)";

			bouton->setStyleSheet(QString("QPushButton { background-color: %1; border: none; }").arg(couleur));
			layout->addWidget(bouton, i, j);
			row.push_back(bouton);
		}
		_button.push_back(row);
	}
	setLayout(layout);
}

Echiquier::~Echiquier()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			delete _button[i][j];
		}
	}
}

void Echiquier::onButtonClicked(int row, int column)
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
		if(_plateau.moveValid(sourceRow, sourceColumn, row, column))
			_tourBlanc = !_tourBlanc;

		updateBoard(sourceRow, sourceColumn);
		updateBoard(row, column);
		sourceRow = -1;
		sourceColumn = -1;
	}
}

void Echiquier::updateBoard(int row, int column) {
	int iconSize = 80;
	Piece* piece = _plateau.getPiece(row, column);

	if (piece) {
		_button[row][column]->setIcon(QIcon(piece->getImagePath()));
		_button[row][column]->setIconSize(QSize(iconSize, iconSize));
	}
	else {
		_button[row][column]->setIcon(QIcon());
	}
}


