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

class GameManager;

class Echiquier : public QWidget
{
	Q_OBJECT
private:
	
	std::vector<std::vector<QPushButton*>> _button;
	Plateau& _plateau;
	QLabel* _tourLabel;
	GameManager* _gameManager;

public:
	Echiquier(Plateau& plateau, GameManager* gameManager);
	~Echiquier();
	void setTourLabel(const QString& text);
	void updateBoard(int row, int column);
};