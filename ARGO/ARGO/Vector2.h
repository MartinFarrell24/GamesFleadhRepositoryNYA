#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>

//
class Vector2
{
public:
	//
	Vector2(float px = 0, float py = 0) :
		x(px),
		y(py)
	{

	}

	//
	~Vector2()
	{

	}

	//
	Vector2 operator * (const float val) const
	{
		return Vector2(x * val, y * val);
	}

	//
	Vector2 operator - (const Vector2 vec) const
	{
		return Vector2(x - vec.x, y - vec.y);
	}

	//
	Vector2 operator + (const Vector2 vec) const
	{
		return Vector2(x + vec.x, y + vec.y);
	}

	//
	Vector2 operator / (const float& rhs)
	{
		return Vector2(x / rhs, y / rhs);
	}

	//
	Vector2& operator+=(const Vector2 vec)
	{
		this->x += vec.x;
		this->y += vec.y;
		return *this;
	}

	//
	bool operator!=(const Vector2& rhs)
	{
		return (x != rhs.x || y != rhs.y);
	}

	//
	bool operator==(const Vector2& rhs)
	{
		return (x == rhs.x && y == rhs.y);
	}

	//
	Vector2& operator*=(const float& x)
	{
		this->x *= x;
		this->y *= x;
		return *this;
	}


	float x, y;

	float X() { return x; };
	float Y() { return y; };
};

#endif // !VECTOR2_H