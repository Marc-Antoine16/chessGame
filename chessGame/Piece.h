#pragma once  
#include <QWidget>  
#include <QPixmap>  
#include "Plateau.h"
#include <QIcon>

class Plateau;

class Piece
{
protected:
    bool _isWhite;
    int _currentRow;
    int _currentColumn;
    QString _imagePath;
    bool _isCaptured;
    bool _hasMoved = false;

    bool _whiteKingMoved = false;  
    bool _blackKingMoved = false;   

public:

    Piece(bool isWhite, QString& imagePath);
    Piece(int currentRow, int currentColumn, bool isWhite, QString& imagePath);
    bool isWhite() const;
    virtual bool possibleMove(int currentRow, int currentColumn, int newRow, int newColumn, bool &isCaptured, Plateau* plateau) const = 0;
    void move(int newRow, int newColumn);
    void setImage(const QString& imagePath);
    QString getImagePath() const;
	virtual std::string getType() const =0;

    virtual void setMoved(bool moved) { _hasMoved = moved; }
    virtual bool hasMoved() const { return _hasMoved; }

    virtual bool whiteKingMoved() const { return _whiteKingMoved; }
    virtual bool blackKingMoved() const { return _blackKingMoved; }

};