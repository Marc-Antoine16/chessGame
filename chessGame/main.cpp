#include "chessGame.h"
#include <QtWidgets/QApplication>
#include <fstream>
#include <QFile>
#include "GameManager.h"
#include <windows.h>


int main(int argc, char* argv[]) 
{
    QApplication app(argc, argv);

	GameManager gameManager(300);
    gameManager.startGame();
    
    return app.exec();
}

