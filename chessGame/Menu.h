#pragma once
#include <QMenuBar>
#include <QMenu>
#include <QAction>

class Menu : public QMenuBar {
    Q_OBJECT

public:
    Menu(QWidget* parent = nullptr);

signals:
    void nouvellePartie();
    void chargerPartie();
    void quitter();
};