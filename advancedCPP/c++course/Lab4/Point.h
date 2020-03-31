#pragma once

#include <iostream>

namespace lab4
{
	class Point
	{
		friend class PolyLine;
		friend std::ostream& operator<<(std::ostream& os, const Point& rhs);
		friend Point operator*(float operand, const Point& other);
	public:
		Point();
		Point(float x, float y);
		~Point();

		Point operator+(const Point& other) const;
		Point operator-(const Point& other) const;
		float Dot(const Point& other) const;
		Point operator*(float operand) const;
		Point& operator=(const Point& rhs);

		float GetX() const;
		float GetY() const;
	private:
		float mX;
		float mY;
	};
}