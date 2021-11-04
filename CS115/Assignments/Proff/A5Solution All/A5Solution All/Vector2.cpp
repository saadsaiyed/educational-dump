//
//  Vector2.cpp
//

#include <cmath>

#include "Vector2.h"



Vector2 :: Vector2 ()
	: x(), y()
{
}

Vector2 :: Vector2 (const float& x1, const float& y1)
	: x(x1), y(y1)
{
}

Vector2 :: Vector2 (const Vector2& original)
	: x(original.x), y(original.y)
{
}

Vector2 :: ~Vector2 ()
{
}

Vector2& Vector2 :: operator= (const Vector2& original)
{
	if(&original != this)
	{
		x = original.x;
		y = original.y;
	}
	return *this;
}

bool Vector2 :: operator== (const Vector2& other)
{
	return (x == other.x && y == other.y);
}

Vector2 Vector2 :: operator+ (const Vector2& addend) const
{
	return Vector2 (x + addend.x, y + addend.y);
}

Vector2 Vector2 :: operator- (const Vector2& subtrahend) const
{
	return Vector2 (x - subtrahend.x, y - subtrahend.y);
}

float Vector2 :: getNorm () const
{
	float x_sqr = x * x;
	float y_sqr = y * y;
	return sqrt(x_sqr + y_sqr);
}
