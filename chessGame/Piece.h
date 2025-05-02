#pragma once
#include <QWidget>
#include <QPixmap>

class Piece
{
protected:
	bool _isWhite;
	int _currentRow;
	int _currentColumn;
	QString _imagePath;
public:
	Piece(bool isWhite, QString& imagePath);
	Piece(int currentRow, int currentColumn, bool isWhite, QString& imagePath);
	bool isWhite() const;
	virtual bool possibleMove(int currentRow, int currentColumn, int newRow, int newColumn) const = 0;
	void move(int newRow, int newColumn);
	void setImage(const QString& imagePath);
	QString getImagePath();
};