#include"PathWalked.h"
#include"Vector2.h"

Element* PathWalked ::copyLinkedList(const Element* p_original_head)
{
	if (p_original_head == nullptr)
		return nullptr;

	Element* p_new_head = new Element;
	p_new_head->datum = p_original_head->datum;

	Element* p_new_prev = p_new_head;
	const Element* p_original_prev = p_original_head;

	while (p_original_prev->next != nullptr)
	{
		p_new_prev->next = new Element;

		p_new_prev = p_new_prev->next;
		p_original_prev = p_original_prev->next;

		p_new_prev->datum = p_original_prev->datum;
	}

	p_new_prev->next = nullptr;

	return p_new_head;
}

void PathWalked::deleteLinkedList(Element *headPtr) const
{
	Element *pCurrent = nullptr;
	Element *pNext = head;
	while (pNext != nullptr)
	{
		pCurrent = pNext;
		pNext = pCurrent->next;
		delete pCurrent;
	}
}

PathWalked :: PathWalked()
{
	this->head = nullptr;
	this->totalPathLength = 0;
}

PathWalked :: PathWalked(const PathWalked& original)
{
	head = copyLinkedList(original.head);
	totalPathLength = original.totalPathLength;
}

PathWalked :: ~PathWalked()
{
	clear();
}

PathWalked& PathWalked :: operator= (const PathWalked& original)
{
	if (&original != this)
	{
		deleteLinkedList(head);
		clear();
		totalPathLength = original.totalPathLength;
	}

	return *this;
}

bool PathWalked :: empty() const
{
	return (head == nullptr);
}

float PathWalked :: getPathLength() const
{
	return totalPathLength;
}

ostream& Element :: operator<< (ostream& out)
{
	out << "(" << datum.x << ", " << datum.y << ")";
	return out;
}

void PathWalked :: print() const
{
	for (Element *p = head; p != nullptr; p = p->next)
	{
		*p << cout;
		cout << endl;
	}
	cout << endl;
}

void PathWalked :: add(const Vector2<float>& position)
{
	Element* tempPtr = new Element;
	tempPtr->datum = position;

	if (head == nullptr)
	{
		tempPtr->next = nullptr;
		head = tempPtr;
	}
	else
	{
		Vector2<float> tempVec = tempPtr->datum - head->datum;

		totalPathLength += tempVec.getNorm();

		tempPtr->next = head;
		head = tempPtr;
	}
}

void PathWalked :: clear()
{
	// The head has to be handled seperately
	Element *pNewHead = new Element;
	pNewHead->datum = head->datum;

	// Copy the rest of the linked list
	Element *pNewPrev = pNewHead;
	const Element *pOldPrev = head;
	while (pOldPrev->next != nullptr)  // still Nodes to copy
	{
		// make a new Node for our copy linked list
		pNewPrev->next = new Element;

		// advance both linked lists 1 position
		pNewPrev = pNewPrev->next;
		pOldPrev = pOldPrev->next;

		// copy the data
		pNewPrev->datum = pOldPrev->datum;
	}

	// set the end of the new linked list to nullptr
	pNewPrev->next = nullptr;

	head = pNewHead;
}

bool PathWalked :: operator< (const Vector2<float>& position)
{
	return head->datum.x < position.x || head->datum.y < position.y;
}


