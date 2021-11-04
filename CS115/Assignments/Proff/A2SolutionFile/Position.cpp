//
// Position.cpp
//

#include <cmath>

#include "Position.h"
#include "Level.h"



Position toPosition (int row, int column)
{
	Position p;
	p.row    = row;
	p.column = column;
	return p;
}



bool areEqual (const Position& p1, const Position& p2)
{
	if(p1.row != p2.row)
		return false;
	if(p1.column != p2.column)
		return false;
	return true;
}

bool isValid (const Position& p)
{
	return (p.row    >= 0)    &&
	       (p.row    <  ROWS) &&
	       (p.column >= 0)    &&
	       (p.column <  COLUMNS);
}

double calculateDistance (const Position& p1,
                          const Position& p2)
{
	int row_diff    = p1.row    - p2.row;
	int column_diff = p1.column - p2.column;

	return sqrt(double((row_diff    * row_diff) +
	                   (column_diff * column_diff)));
}

