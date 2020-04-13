#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

class Vector2
{
public:
	float x, y;

	inline Vector2(float x_ = 0, float y_ = 0) : x(x_), y(y_) {}
	inline ~Vector2() {}

	inline Vector2 operator+(const Vector2 v_) const
	{
		return Vector2(x + v_.x, y + v_.y);
	}

	inline Vector2 operator-(const Vector2 v_) const
	{
		return Vector2(x - v_.x, y - v_.y);
	}

	inline Vector2& operator+=(const Vector2 v_)
	{
		x += v_.x;
		y += v_.y;
		return *this;
	}

	inline Vector2& operator-=(const Vector2 v_)
	{
		x -= v_.x;
		y -= v_.y;
		return *this;
	}

	inline Vector2 operator*(const float s_) const
	{
		return Vector2(x * s_, y * s_);
	}

	inline Vector2 operator/(const float s_) const
	{
		return Vector2(x / s_, y / s_);
	}

	inline float dot(const Vector2 v_) const
	{
		return (x * v_.x + y * v_.y);
	}

	inline float mag(const Vector2 v_) const
	{
		return sqrt(x * x + y * y);
	}

	inline float distance(const Vector2 v_) const
	{
		Vector2 r = *this - v_;
		return mag(r);
	}

};

#endif
