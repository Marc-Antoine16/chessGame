#pragma once  
#include "Piece.h"  
#include <vector>  


class Piece; // Forward declaration of Piece class sinon erreur  

class Echiquier; 

class Plateau : public QWidget
{  
private:  
Piece* _grid[8][8];  
Echiquier* _echiquier; 

public:  
Plateau(Echiquier* echiquier); 
Plateau();

Piece* getPiece(int row, int column) const;
void placer(Piece* piece, int row, int column);  
bool moveValid(int currentRow, int currentColumn, int newRow, int newColumn, Plateau *plateau);  
void deplacer(int currentRow, int currentColumn, int newRow, int newColumn);  
bool isOccupied(int row, int column) const;  
void setEchiquier(Echiquier* echiquier);
};