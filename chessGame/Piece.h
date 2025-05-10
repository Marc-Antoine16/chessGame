#pragma once  
#include <QWidget>  
#include <QPixmap>  
#include "Plateau.h"

class Plateau;

class Piece
{
protected:
    bool _isWhite;
    int _currentRow;
    int _currentColumn;
    QString _imagePath;
    bool _isCaptured;

public:

    Piece(bool isWhite, QString& imagePath);
    Piece(int currentRow, int currentColumn, bool isWhite, QString& imagePath);
    bool isWhite() const;
    virtual bool possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool &isCaptured, Plateau* plateau) const = 0;
    virtual std::string getType() const = 0;
    void move(int newRow, int newColumn);
    void setImage(const QString& imagePath);
    QString getImagePath() const;
	virtual Piece* clone() const = 0;
};