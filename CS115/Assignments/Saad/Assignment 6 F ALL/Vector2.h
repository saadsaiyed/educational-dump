#pragma once
#ifndef VECTOR2_H
#define VECTOR2_H


#include <iostream>

using namespace std;

template <typename ItemType>
class Vector2
{
public:
	Vector2();
	Vector2(const ItemType& x1, const ItemType& y1);
	Vector2(const Vector2<ItemType>& original);
	~Vector2();  // empty
	Vector2<ItemType>& operator= (const Vector2<ItemType>& original);
	bool operator== (const Vector2<ItemType>& other) const;
	Vector2<ItemType> operator+ (const Vector2<ItemType>& addend) const;
	Vector2<ItemType> operator- (const Vector2<ItemType>& subtrahend) const;
	float getNorm() const;

	ItemType x;
	ItemType y;
};


#endif