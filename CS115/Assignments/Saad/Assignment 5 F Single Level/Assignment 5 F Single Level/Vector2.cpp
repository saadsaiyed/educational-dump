#include "Vector2.h"

Vector2 :: Vector2() : x(0), y(0)
{
}

Vector2 :: Vector2(const float& x1, const float& y1) : x(x1), y(y1)
{
}

Vector2 :: Vector2(const Vector2& original)
{
	this->x = original.x;
	this->y = original.y;
}

Vector2 :: ~Vector2()  // empty
{
}

Vector2& Vector2 :: operator= (const Vector2& original)
{
	if (this == &original)
		return *this;

	this->x = original.x;
	this->y = original.y;

	return *this;
}

bool Vector2 :: operator== (const Vector2& other) const
{
	return (this->x == other.x && this->y == other.y);
}

Vector2 Vector2 :: operator+ (const Vector2& addend) const
{
	Vector2 temp;

	temp.x = this->x + addend.x;
	temp.y = this->y + addend.y;

	return temp;
}

Vector2 Vector2 :: operator- (const Vector2& subtrahend) const 
{
	Vector2 temp;

	temp.x = this->x - subtrahend.x;
	temp.y = this->y - subtrahend.y;

	return temp;
}

float Vector2::getNorm() const
{
	return pow((pow(x, 2.0f) + pow(y , 2.0f)), 0.5f);
}