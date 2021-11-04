//
//  Vector2.h
//
//  A class to represent a 2D position using Cartesian
//    coordinates using signed integers.
//

#pragma once



class Vector2
{
public:
	Vector2 ();
	Vector2 (const float& x1, const float& y1);
	Vector2 (const Vector2& original);
	~Vector2 ();
	Vector2& operator= (const Vector2& original);

	bool operator== (const Vector2& other);
	Vector2 operator+ (const Vector2& addend) const;
	Vector2 operator- (const Vector2& subtrahend) const;
	float getNorm () const;

public:
	float x;
	float y;
};

