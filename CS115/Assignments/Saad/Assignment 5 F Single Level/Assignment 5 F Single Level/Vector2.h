#pragma once
#ifndef VECTOR2_H
#define VECTOR2_H


#include <iostream>

using namespace std;

class Vector2
{
public:
	Vector2();
	Vector2(const float& x1, const float& y1);
	Vector2(const Vector2& original);
	~Vector2();  // empty
	Vector2& operator= (const Vector2& original);
	bool operator== (const Vector2& other) const;
	Vector2 operator+ (const Vector2& addend) const;
	Vector2 operator- (const Vector2& subtrahend) const;

	float getNorm() const;

	float x;
	float y;
};


#endif