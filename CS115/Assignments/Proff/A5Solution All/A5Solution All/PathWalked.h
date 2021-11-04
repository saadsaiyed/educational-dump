//
//  PathWalked.h
//

#pragma once

#include "Vector2.h"

struct Element;



//
//  PathWalked
//
//  A class to represent a 2D path and calculate its length.
//
//  Class Invariant:
//    <1> (p_head == NULL) == (element_count == 0)
//    <2> path_length >= 0.0f
//
class PathWalked
{
public:
	PathWalked ();
	PathWalked (const PathWalked& original);
	~PathWalked ();
	PathWalked& operator= (const PathWalked& original);

	bool empty () const;
	float getPathLength () const;

	void print () const;

	void add (const Vector2& position);
	void clear ();

private:
	Element* copyLinkedList (const Element* p_original_head) const;
	bool invariant () const;

private:
	Element* p_head;
	unsigned int element_count;
	float path_length;
};




struct Element
{
	Vector2 position;
	Element* p_next;
};
