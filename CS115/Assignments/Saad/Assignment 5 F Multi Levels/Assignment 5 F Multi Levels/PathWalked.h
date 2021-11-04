#pragma once
#ifndef PATHWALKED_H
#define PATHWALKED_H

#include"Game.h"
#include"Vector2.h"

struct Element;

class PathWalked
{
private:

	Element* head = nullptr;
	float totalPathLength;
	Element* copyLinkedList(const Element* p_original_head);

public:

	PathWalked();

	PathWalked(const PathWalked& original);

	~PathWalked();

	PathWalked& operator= (const PathWalked& original);

	bool empty() const;

	float getPathLength() const;

	void print() const;

	void add(const Vector2& position);

	void clear();

	void deleteLinkedList(Element* headPtr) const;

	bool operator< (const Vector2& position);
};

struct Element
{
	Vector2 head;
	Element* next;
	ostream& operator<< (ostream& out);
};

#endif