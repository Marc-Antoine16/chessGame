#include "Echiquier.h"
#include <QGridLayout>
#include <QIcon>

using namespace std;

Echiquier::Echiquier(Plateau& plateau, GameManager* gameManager) : _plateau(plateau), _gameManager(gameManager)
{
	QGridLayout* layout = new QGridLayout(this);
	layout->setSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);

	_tourLabel = new QLabel("Tour des blancs", this);
	_tourLabel->setStyleSheet("font-family: 'Times New Roman'; font-size: 30px; font-weight: bold; font-style: oblique; color: rgb(250, 250, 250);");

	layout->addWidget(_tourLabel, 0, 0, 1, 8, Qt::AlignCenter);
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
					_gameManager->onButtonClicked(i, j);
				});

			QString couleur = ((i + j) % 2 == 0) ? "rgb(210, 180, 140)" : "rgb(101, 67, 33)";

			bouton->setStyleSheet(QString("QPushButton { background-color: %1; border: none; }").arg(couleur));
			layout->addWidget(bouton, i + 1, j);
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

void Echiquier::setTourLabel(const QString& text)
{
	_tourLabel->setText(text);
	_tourLabel->repaint();
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