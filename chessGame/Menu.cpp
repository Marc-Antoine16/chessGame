#include "Menu.h"

Menu::Menu(QWidget* parent) : QMenuBar(parent) {
    QMenu* menuFichier = addMenu("Fichier");

    QAction* nouvelle = menuFichier->addAction("Nouvelle partie");
    QAction* charger = menuFichier->addAction("Charger une partie");
    QAction* quitterApp = menuFichier->addAction("Quitter");

    connect(nouvelle, &QAction::triggered, this, &Menu::nouvellePartie);
    connect(charger, &QAction::triggered, this, &Menu::chargerPartie);
    connect(quitterApp, &QAction::triggered, this, &Menu::quitter);
}