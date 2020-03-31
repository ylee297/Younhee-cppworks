#include <iostream>
#include "Point.h"


namespace lab4
{
	Point::Point()
	{

	}
	Point::Point(float x, float y)
		:   mX(x),
			mY(y)
	{
	}

	Point::~Point()
	{
	}

	Point Point::operator+(const Point& other) const
	{
		return Point(mX + other.mX, mY + other.mY);
	}

	Point Point::operator-(const Point& other) const
	{
		return Point(mX - other.mX, mY - other.mY);
	}

	float Point::Dot(const Point& other) const
	{
		return (mX * other.mX) + (mY * other.mY);
	}

	Point Point::operator*(float operand) const
	{
		return Point(mX * operand, mY * operand);
	}

	Point operator*(float operand, const Point& other)
	{
		return Point(other.mX * operand, other.mY * operand);
	}

	std::ostream& operator<<(std::ostream& os, const Point& rhs)
	{
		os << "X cord : " << rhs.mX << " , Y cord : " << rhs.mY;
		return os;
	}

	Point& Point::operator=(const Point& rhs)
	{
		mX = rhs.mX;
		mY = rhs.mY;
		return *this;
	}

	float Point::GetX() const
	{
		return mX;
	}

	float Point::GetY() const
	{
		return mY;
	}
}