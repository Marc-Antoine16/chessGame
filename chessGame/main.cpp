#include "chessGame.h"
#include <QtWidgets/QApplication>
#include <fstream>
#include <QFile>
#include "GameManager.h"


int main(int argc, char* argv[]) 
{
    QApplication app(argc, argv);

	GameManager gameManager;
    gameManager.startGame();

    return app.exec();
}

