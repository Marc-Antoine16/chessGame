#include "chessGame.h"
#include <QtWidgets/QApplication>
#include <fstream>
#include <QFile>
#include "GameManager.h"
#include <windows.h>


int main(int argc, char* argv[]) 
{
    int temps_secondes = 300;
    QApplication app(argc, argv);

	GameManager gameManager(temps_secondes);
    gameManager.startGame();
    
    return app.exec();
}

