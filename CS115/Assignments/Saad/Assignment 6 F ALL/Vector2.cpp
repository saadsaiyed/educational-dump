#include "Vector2.h"

template <typename ItemType>
Vector2<ItemType> :: Vector2() : x(0), y(0)
{
}

template <typename ItemType>
Vector2<ItemType> :: Vector2(const ItemType& x1, const ItemType& y1) : x(x1), y(y1)
{
}

template <typename ItemType>
Vector2<ItemType> :: Vector2(const Vector2& original)
{
	this->x = original.x;
	this->y = original.y;
}

template <typename ItemType>
Vector2<ItemType> :: ~Vector2()  // empty
{

}

template <typename ItemType>
Vector2<ItemType>& Vector2<ItemType> :: operator= (const Vector2<ItemType>& original)
{
	if (this == &original)
		return *this;

	this->x = original.x;
	this->y = original.y;

	return *this;
}

template <typename ItemType>
bool Vector2<ItemType> :: operator== (const Vector2<ItemType>& other) const
{
	return (this->x == other.x && this->y == other.y);
}

template <typename ItemType>
Vector2<ItemType> Vector2<ItemType> :: operator+ (const Vector2<ItemType>& addend) const
{
	Vector2 temp;

	temp.x = this->x + addend.x;
	temp.y = this->y + addend.y;

	return temp;
}

template <typename ItemType>
Vector2<ItemType> Vector2<ItemType> :: operator- (const Vector2<ItemType>& subtrahend) const
{
	Vector2 temp;

	temp.x = this->x - subtrahend.x;
	temp.y = this->y - subtrahend.y;

	return temp;
}

template <typename ItemType>
float Vector2<ItemType> :: getNorm() const
{
	return pow((pow((float)(x), 2) + pow((float)(y) , 2)), 0.5);
}

template class Vector2 <int>;
template class Vector2 <double>;
template class Vector2 <float>;