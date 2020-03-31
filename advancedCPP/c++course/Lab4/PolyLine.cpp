#include <iostream>
#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		:   mSize(0)
	{
		mPoints = new const Point*[10];
	}

	PolyLine::PolyLine(const PolyLine& other)
		:   mSize(other.mSize)
	{
		mPoints = new const Point*[10];
		for (unsigned int i = 0; i < 10; i++)
		{
			if (i < mSize)
			{
				mPoints[i] = new Point(other.mPoints[i]->GetX(), other.mPoints[i]->GetY());
			}
			else
			{
				mPoints[i] = nullptr;
			}
		}
	}

	PolyLine::~PolyLine()
	{
		DelPoints(mPoints);
	}

	bool PolyLine::AddPoint(float x, float y)
	{

		if (mSize == 10)
		{
			return false;
		}

		mPoints[mSize] = new Point(x, y);
		mSize++;

		return true;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mSize == 10 || point == nullptr)
		{
			return false;
		}

		mPoints[mSize] = point;
		mSize++;

		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i + 1 > mSize || i < 0)
		{
			return false;
		}

		delete mPoints[i];

		while (i < mSize - 1)
		{
			mPoints[i] = mPoints[i + 1];
			i++;
		}

		mPoints[--mSize] = nullptr;


		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mSize == 0)
		{
			return false;
		}

		float maxX = mPoints[0]->GetX();
		float maxY = mPoints[0]->GetY();
		float minX = mPoints[0]->GetX();
		float minY = mPoints[0]->GetY();

		for (unsigned int i = 1; i < mSize; i++)
		{
			if (mPoints[i]->GetX() > maxX)
			{
				maxX = mPoints[i]->GetX();
			}
			else if (mPoints[i]->GetX() < minX)
			{
				minX = mPoints[i]->GetX();
			}

			if (mPoints[i]->GetY() > maxY)
			{
				maxY = mPoints[i]->GetY();
			}
			else if (mPoints[i]->GetY() < minY)
			{
				minY = mPoints[i]->GetY();
			}
		}


		outMin->mX = minX;
		outMin->mY = minY;
		outMax->mX = maxX;
		outMax->mY = maxY;

		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i < mSize && i >= 0)
		{
			return mPoints[i];
		}
		else
		{
			return nullptr;
		}
	}

	PolyLine& PolyLine::operator=(const PolyLine& other)
	{
		if (this != &other)
		{
			DelPoints(mPoints);
			mSize = other.mSize;
			mPoints = new const Point *[10];
			for (unsigned int i = 0; i < mSize; i++)
			{
				if (i < mSize)
				{
					mPoints[i] = new Point(other.mPoints[i]->GetX(), other.mPoints[i]->GetY());
				}
				else
				{
					mPoints[i] = nullptr;
				}
			}
		}
		return *this;
	}

	void PolyLine::DelPoints(Point const** pointers)
	{
		for (unsigned int i = 0; i < mSize; i++)
		{
			delete pointers[i];
		}
		delete []pointers;
	}

}
