#pragma once
#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <vector>
#include <QLabel>
#include "Plateau.h"
#include <QGridLayout>
#include "Pawn.h"
#include "GameManager.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMainWindow>
#include <QColorDialog>

class GameManager;

class Echiquier : public QMainWindow
{
	Q_OBJECT

protected:
	void closeEvent(QCloseEvent* event) override;

private:
	std::vector<std::vector<QPushButton*>> _button;
	Plateau& _plateau;
	QLabel* _tourLabel;
	QLabel* _timerBlancLabel;
	QLabel* _timerNoirLabel;
	GameManager* _gameManager;
	QColor _couleurClair = QColor(210, 180, 140);
	QColor _couleurFonce = QColor(101, 67, 33);

public:
	Echiquier(Plateau& plateau, GameManager* gameManager);
	~Echiquier();
	void setTourLabel(const QString& text);
	void updateBoard(int row, int column);
	void higlightSquare(int row, int column);
	void updateTimerLabel(int temps, bool estBlanc);
	void resetBoard();
	void changerCouleurPlateau();

signals:
	void nouvellePartieDemandee();
	void chargementPartieDemande();
	void fenetreFermee();


private slots:
	void demanderNouvellePartie();
	void demanderChargerPartie();
};