//
// Position.h
//
// A module to represent a position in a 2D grid-based game.
//

#pragma once



struct Position
{
	int row;
	int column;
};



//
//  toPosition
//
//  Purpose: To create a Position from the specified row and
//           column values.
//  Parameter(s):
//    <1> row: The row for the position
//    <2> column: The column for the position
//  Precondition(s): N/A
//  Returns: A Position representing row row and column column.
//  Side Effects: N/A
//
Position toPosition (int row, int column);

//
//  areEqual
//
//  Purpose: To determine if two Positions represent the same
//           row and column.
//  Parameter(s):
//    <1> p1: The first position to check
//    <2> p2: The second position to check
//  Precondition(s): N/A
//  Returns: Whether p1 and p2 represent the same row and
//           column.
//  Side Effects: N/A
//
bool areEqual (const Position& p1,
               const Position& p2);

//
//  isValid
//
//  Purpose: To determine if a Position is valid.
//  Parameter(s):
//    <1> p: The position to check
//  Precondition(s): N/A
//  Returns: Whether p is inside the level.
//  Side Effects: N/A
//
bool isValid (const Position& p);

//
//  calculateDistance
//
//  Purpose: To determine the Euclidean distance between two
//           Positions.
//  Parameter(s):
//    <1> p1: The first position
//    <2> p2: The second position
//  Precondition(s): N/A
//  Returns: The distance from p1 to p2.
//  Side Effects: N/A
//
double calculateDistance (const Position& p1,
                          const Position& p2);
