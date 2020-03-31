#include <math.h>
#include "TimeSheet.h"

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		:   mMaxEntries(maxEntries),
			mName(name)
	{
		mTimeSheet = new float[maxEntries];
		mSize = 0;
		mAverage = 0;
		mTotal = 0;
	}

	TimeSheet::~TimeSheet()
	{
		delete []mTimeSheet;
	}

	TimeSheet::TimeSheet(const TimeSheet& other)
		:   mSize(other.mSize),
			mMaxEntries(other.mMaxEntries),
			mAverage(other.mAverage),
			mTotal(other.mTotal),
			mName(other.mName)
	{
		mTimeSheet = new float[other.mMaxEntries];
		for (int i = 0; i < other.mSize; i++)
		{
			mTimeSheet[i] = other.mTimeSheet[i];
		}
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (mSize < mMaxEntries && timeInHours > 0 && timeInHours <= 10)
		{
			mAverage *= mSize;
			mAverage = (mAverage + timeInHours) / (mSize + 1);

			mTimeSheet[mSize] = float(timeInHours);
			mSize++;
			mTotal += timeInHours;
		}

	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index < unsigned(mSize))
		{
			return int(mTimeSheet[index]);
		}
		else
		{
			return -1;
		}
	}

	int TimeSheet::GetTotalTime() const
	{
		return mTotal;
	}

	float TimeSheet::GetAverageTime() const
	{
		if (mSize == 0)
		{
			return 0.0f;
		}

		return mAverage;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		if (mSize == 0)
		{
			return 0.0f;
		}

		float average = GetAverageTime();
		float numerator = 0;
		for (int i = 0; i < mSize; i++)
		{
			numerator += powf(mTimeSheet[i] - average, 2);
		}

		return sqrtf(numerator / mSize);
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}

	TimeSheet& TimeSheet::operator=(const TimeSheet& rhs)
	{
		mSize = rhs.mSize;
		mMaxEntries = rhs.mMaxEntries;
		mName = rhs.mName;
		mAverage = rhs.mAverage;
		mTotal = rhs.mTotal;

		for (int i = 0; i < rhs.mSize; i++)
		{
			mTimeSheet[i] = rhs.mTimeSheet[i];
		}

		return *this;
	}
}