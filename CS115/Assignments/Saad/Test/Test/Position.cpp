#include "Position.h"
#include "Level.h"

using namespace std;

Position toPosition(int row, int column)
{
	Position p;

	p.row = row;
	p.column = column;

	return p;
}

bool areEqual(const Position& p1, const Position& p2)
{
	if (p1.row == p2.row && p1.column == p2.column)
		return true;

	return false;
}

bool isValid(const Position& p1)
{
	if (p1.row < ROWS && p1.column < COLUMNS)
		return true;

	return false;	
}

double calculateDistance(const Position& p1, const Position& p2)
{
	double Result, Term1, Term2, P1row, P1column, P2row, P2column;

	P1row = p1.row;
	P1column = p1.column;
	P2row = p2.row;
	P2column = p2.column;

	Term1 = pow(P2row - P1row, 2.0);
	Term2 = pow(P2column - P1column, 2.0);
	Result = pow(Term1 + Term2, 0.5);
	
	return Result;
}