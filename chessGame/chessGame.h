#pragma once

#include <QtWidgets/QWidget>
#include "ui_chessGame.h"

class chessGame : public QWidget
{
    Q_OBJECT

public:
    chessGame(QWidget *parent = nullptr);
    ~chessGame();

private:
    Ui::chessGameClass ui;
};
