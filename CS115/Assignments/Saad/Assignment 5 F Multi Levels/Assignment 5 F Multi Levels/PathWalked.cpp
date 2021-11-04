#include"PathWalked.h"
#include"Vector2.h"

Element* PathWalked ::copyLinkedList(const Element* p_original_head)
{
	if (p_original_head == nullptr)
		return nullptr;

	Element* p_new_head = new Element;
	p_new_head->head = p_original_head->head;

	Element* p_new_prev = p_new_head;
	const Element* p_original_prev = p_original_head;	//why does compiler not giving error if we change the const value there

	while (p_original_prev->next != nullptr)
	{
		p_new_prev->next = new Element;

		p_new_prev = p_new_prev->next;
		p_original_prev = p_original_prev->next;		//here

		p_new_prev->head = p_original_prev->head;
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

void PathWalked :: print() const
{
	for (Element *p = head; p != nullptr; p = p->next)
	{
		p->operator<<(cout);

		//*p << cout;
		cout << endl;
	}
	cout << endl;
}

void PathWalked :: add(const Vector2& position)
{
	Element* tempPtr = new Element;
	tempPtr->head = position;

	if (head == nullptr)
	{
		tempPtr->next = nullptr;
		head = tempPtr;
	}
	else
	{
		Vector2 tempVec = tempPtr->head - head->head;
		
		totalPathLength += tempVec.getNorm();

		tempPtr->next = head;
		head = tempPtr;
	}
}

void PathWalked :: clear()
{
	// The head has to be handled seperately
	Element *pNewHead = new Element;
	pNewHead->head = head->head;

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
		pNewPrev->head = pOldPrev->head;
	}

	// set the end of the new linked list to nullptr
	pNewPrev->next = nullptr;

	head = pNewHead;
}

bool PathWalked :: operator< (const Vector2& position)
{
	return head->head.x < position.x || head->head.y < position.y;
}

ostream& Element :: operator<< (ostream& out)
{
	out << "(" << head.x << ", " << head.y << ")";
	return out;
}
