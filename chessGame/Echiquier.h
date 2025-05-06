#pragma once
#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <vector>
#include <QLabel>
#include "Plateau.h"
#include <QGridLayout>
#include "Pawn.h"

class Echiquier : public QWidget
{
	Q_OBJECT
private:
	
	std::vector<std::vector<QPushButton*>> _button;
	QLabel* _labels[8][8];
	Plateau _plateau;
	int _tour;

public:
	Echiquier(Plateau &plateau);
	~Echiquier();
	void onButtonClicked(int row, int column);
	void updateBoard();

	
};