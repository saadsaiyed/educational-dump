/*
Name: Saad Saiyed
Course: CS 115
Assignment: 2
Lab Section: Section 084
Section: 5:30pm to 6:30pm
Date: 02/04/19
*/

#ifndef POSITION_H
#define POSITION_H


struct Position
{
	unsigned int row;
	unsigned int column;
};

Position toPosition(int row, int column);
bool areEqual(const Position& p1, const Position& p2);
bool isValid(const Position& p1);
double calculateDistance(const Position& p1, const Position& p2);

#endif