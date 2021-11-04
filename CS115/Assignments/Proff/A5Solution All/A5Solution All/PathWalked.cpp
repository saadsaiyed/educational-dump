//
//  PathWalked.cpp
//

#include <cassert>
#include <iostream>

#include "Vector2.h"
#include "PathWalked.h"

using namespace std;



PathWalked :: PathWalked ()
{
	p_head        = NULL;
	element_count = 0;
	path_length   = 0.0f;

	assert(invariant());
}

PathWalked :: PathWalked (const PathWalked& original)
{
	p_head        = copyLinkedList(original.p_head);
	element_count = original.element_count;
	path_length   = original.path_length;

	assert(invariant());
}

PathWalked :: ~PathWalked ()
{
	clear();
	assert(p_head == NULL);
}

PathWalked& PathWalked :: operator= (const PathWalked& original)
{
	if(&original != this)
	{
		clear();
		assert(p_head == NULL);

		p_head        = copyLinkedList(original.p_head);
		element_count = original.element_count;
		path_length   = original.path_length;
	}

	assert(invariant());
	return *this;
}



bool PathWalked :: empty () const
{
	return (p_head == NULL);
}

float PathWalked :: getPathLength () const
{
	return path_length;
}



void PathWalked :: print () const
{
	for(const Element* p_current = p_head;
	    p_current != NULL;
	    p_current = p_current->p_next)
	{
		cout << "("  << p_current->position.x
		     << ", " << p_current->position.y << ")" << endl;
	}
}



void PathWalked :: add (const Vector2& position)
{
	Element* p_new_head  = new Element;
	p_new_head->position = position;
	p_new_head->p_next   = p_head;

	if(p_head != NULL)
	{
		Vector2 difference = p_head->position - position;
		path_length += difference.getNorm();
	}

	p_head = p_new_head;
	element_count++;

	assert(invariant());
}

void PathWalked :: clear ()
{
	Element* p_current = p_head;
	while(p_current != NULL)
	{
		Element* p_previous = p_current;
	    p_current = p_current->p_next;
		delete p_previous;
	}

	p_head        = NULL;
	element_count = 0;
	path_length   = 0.0f;

	assert(p_head == NULL);
	assert(invariant());
}



Element* PathWalked :: copyLinkedList (const Element* p_original_head) const
{
	if(p_original_head == NULL)
		return NULL;

	// else there is a linked list to copy

	// copy the first Element
	Element* p_copy_head  = new Element;
	p_copy_head->position = p_original_head->position;
	p_copy_head->p_next     = NULL;

	const Element* p_original_current = p_original_head;
	Element*       p_copy_current     = p_copy_head;
	assert(p_original_current != NULL);
	assert(p_copy_current     != NULL);

	while(p_original_current->p_next != NULL)
	{
		assert(p_original_current != NULL);

		// get the Element to copy
		Element* p_original_next = p_original_current->p_next;
		assert(p_original_next != NULL);

		// create the copy
		Element* p_copy_next  = new Element;
		p_copy_next->position = p_original_next->position;
		p_copy_next->p_next   = NULL;

		// attach in the copy
		p_copy_current->p_next = p_copy_next;

		// move on to the next Element
		p_original_current = p_original_current->p_next;
		p_copy_current     = p_copy_current    ->p_next;
	}

	return p_copy_head;
}

bool PathWalked :: invariant () const
{
	if ((p_head == NULL) != (element_count == 0)) return false;
	if (path_length < 0.0f) return false;
	return true;
}
