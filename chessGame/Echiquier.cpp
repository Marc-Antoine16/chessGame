#include "Echiquier.h"
#include <QGridLayout>
#include <QIcon>
#include <QCloseEvent>

using namespace std;

Echiquier::Echiquier(Plateau& plateau, GameManager* gameManager) : QMainWindow(), _plateau(plateau), _gameManager(gameManager)
{
	this->setStyleSheet("background-color: lightgray;");
	QWidget* centralWidget = new QWidget(this);
	setCentralWidget(centralWidget);

	QGridLayout* layout = new QGridLayout(centralWidget);

	QMenuBar* menuBar = new QMenuBar(this);
	QMenu* menuFichier = new QMenu("MENU", this);
	menuFichier->setStyleSheet("background-color: lightgray; color: black; font-size: 20px; font-weight: bold; font-style: oblique; padding : 5px;border: 3px solid white;");
	menuBar->setStyleSheet("background-color: lightgray; color: black; font-size: 20px; font-weight: bold; padding : 5px;");

	QAction* actionNouvelle = new QAction("Nouvelle partie", this);
	QAction* actionCharger = new QAction("Charger une partie", this);
	QAction* actionChangerCouleur = new QAction("Changer couleur du plateau", this);
	QAction* actionQuitter = new QAction("Quitter", this);

	menuFichier->addAction(actionNouvelle);
	menuFichier->addAction(actionCharger);
	menuFichier->addSeparator();
	menuFichier->addAction(actionChangerCouleur);
	menuFichier->addSeparator();
	menuFichier->addAction(actionQuitter); 
	

	

	menuBar->addMenu(menuFichier);
	setMenuBar(menuBar);

	connect(actionNouvelle, &QAction::triggered, this, &Echiquier::demanderNouvellePartie);
	
	connect(actionCharger, &QAction::triggered, this, &Echiquier::demanderChargerPartie);
	connect(actionChangerCouleur, &QAction::triggered, this, &Echiquier::changerCouleurPlateau);
	connect(actionQuitter, &QAction::triggered, this, & QWidget::close);

	layout->setSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);

	QHBoxLayout* topLayout = new QHBoxLayout();
	topLayout->setSpacing(100);

	_timerBlancLabel = new QLabel("05:00", this);
	_timerBlancLabel->setStyleSheet("font-family: 'Times New Roman'; font-size: 30px; font-weight: bold; font-style: oblique; color: black; padding : 5px;");
	topLayout->addWidget(_timerBlancLabel);

	_tourLabel = new QLabel("Tour des blancs", this);
	_tourLabel->setStyleSheet("font-family: 'Times New Roman'; font-size: 30px; font-weight: bold; font-style: oblique; color: black; padding : 5px;");
	topLayout->addWidget(_tourLabel);

	_timerNoirLabel = new QLabel("05:00", this);
	_timerNoirLabel->setStyleSheet("font-family: 'Times New Roman'; font-size: 30px; font-weight: bold; font-style: oblique; color: black; padding : 5px;");
	topLayout->addWidget(_timerNoirLabel);

	layout->addLayout(topLayout, 0, 0, 1, 8, Qt::AlignCenter);

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

			QString couleur = ((i + j) % 2 == 0) ? _couleurClair.name() : _couleurFonce.name();
			bouton->setStyleSheet(QString("QPushButton { background-color: %1; border: none; }").arg(couleur));

			layout->addWidget(bouton, i + 1, j);
			row.push_back(bouton);
		}
		_button.push_back(row);
	}
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
	_tourLabel->setStyleSheet("font-family: 'Times New Roman'; font-size: 30px; font-weight: bold; font-style: oblique; color: black; padding : 5px");
	_tourLabel->repaint();
}

void Echiquier::updateTimerLabel(int temps, bool estBlanc) {
	
		int minutes = temps / 60;
		int secondes = temps % 60;
		QString timeText = QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(secondes, 2, 10, QChar('0'));

		if (estBlanc) {
			_timerBlancLabel->setText(timeText);
		}
		else {
			_timerNoirLabel->setText(timeText);
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

void Echiquier::higlightSquare(int row, int column)
{
	Piece* piece = _plateau.getPiece(row, column);
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			QString couleur = ((i + j) % 2 == 0) ? _couleurClair.name() : _couleurFonce.name();
			_button[i][j]->setStyleSheet(QString("QPushButton { background-color: %1; border: none; }").arg(couleur));
		}
	}

	if (!piece)
		return;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			bool isCaptured = false;
			if (piece->possibleMove(row, column, i, j, isCaptured, &_plateau))
			{
				Plateau copie = _plateau;
				copie.deplacer(row, column, i, j);

				if (!copie.inCheck(piece->isWhite()))
				{
					if (isCaptured)
					{
						_button[i][j]->setStyleSheet("QPushButton { background-color: rgba(255, 69, 0, 150); border: 3px solid rgba(178, 34, 34, 1); }");
					}
					else
					{
						_button[i][j]->setStyleSheet("QPushButton { background-color: rgb(173, 216, 230); border: 3px solid rgba(135, 206, 250, 1); }");
					}
				}
			}
		}
	}
}

void Echiquier::demanderNouvellePartie() {
	emit nouvellePartieDemandee();
}

void Echiquier::demanderChargerPartie() {
	emit chargementPartieDemande();
}

void Echiquier::closeEvent(QCloseEvent* event)
{
	if (_gameManager)
	{
		_gameManager->putInCsv(_plateau.getMoveDone());
	}
	emit fenetreFermee();
	QMainWindow::closeEvent(event);
}

void Echiquier::resetBoard() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			updateBoard(i, j);
		}
	}
}

void Echiquier::changerCouleurPlateau()
{
	QColor color1 = QColorDialog::getColor(Qt::white, this, "Couleur des cases claires");
	QColor color2 = QColorDialog::getColor(Qt::black, this, "Couleur des cases foncees");

	if (!color1.isValid() || !color2.isValid()) return;

	_couleurClair = color1;
	_couleurFonce = color2;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			QString couleur = ((i + j) % 2 == 0) ? color1.name() : color2.name();
			_button[i][j]->setStyleSheet(QString("QPushButton { background-color: %1; border: none; }").arg(couleur));
		}
	}
}