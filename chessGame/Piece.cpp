#include "Piece.h"
#include <iostream>
#include "Plateau.h"

Piece::Piece(bool isWhite, QString& imagePath)
{
    _currentRow = 0;
    _currentColumn = 0;
    _isWhite = isWhite;
    _imagePath = imagePath;
    setImage(_imagePath);
}

Piece::Piece(int currentRow, int currentColumn, bool isWhite, QString& imagePath)
{
    _currentRow = currentRow;
    _currentColumn = currentColumn;
    _isWhite = isWhite;
    _imagePath = imagePath;
    setImage(_imagePath);
}

bool Piece::isWhite() const
{
    return _isWhite;
}

void Piece::move(int newRow, int newColumn)
{
    _currentRow = newRow;
    _currentColumn = newColumn;
}

void Piece::setImage(const QString& imagePath)
{
    _imagePath = imagePath;
}

QString Piece::getImagePath() const
{
    return _imagePath;
}