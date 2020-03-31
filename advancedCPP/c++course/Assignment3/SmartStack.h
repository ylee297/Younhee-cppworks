#pragma once
#include <stack>
#include <limits>
#include <cmath>

using namespace std;

namespace assignment3
{
	template<typename T>
	class SmartStack
	{
	private:
		stack<T> mStack;
		stack<T> mMaxStack;
		stack<T> mMinStack;
		unsigned int mTotalSize;
		double mSum;
		double mExSum;
	public:
		SmartStack();
		~SmartStack();
		void Push(T a);
		T Pop();
		const T& Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		const unsigned int& GetCount();
	};


	template<typename T>
	inline SmartStack<T>::SmartStack()
		:	mSum(0), mTotalSize(0), mExSum(0)
	{
	}

	template<typename T>
	inline SmartStack<T>::~SmartStack()
	{
	}

	template<typename T>
	inline void SmartStack<T>::Push(T a)
	{
		mSum += a;
		mExSum += pow(a, 2);
		mStack.push(a);

		if (mTotalSize == 0)
		{
			mMinStack.push(a);
			mMaxStack.push(a);
			mTotalSize++;
			return;
		}

		if (a < mMinStack.top())
		{
			mMinStack.push(a);
		}
		else
		{
			mMinStack.push(mMinStack.top());
		}

		if (a > mMaxStack.top())
		{
			mMaxStack.push(a);
		}
		else
		{
			mMaxStack.push(mMaxStack.top());
		}

		mTotalSize++;
	}

	template<typename T>
	inline T SmartStack<T>::Pop()
	{
		T a = mStack.top();
		mExSum -= pow(a, 2);
		mTotalSize--;
		mSum -= a; 
		mStack.pop();
		mMaxStack.pop();
		mMinStack.pop();
		return a;
	}

	template<typename T>
	inline const T& SmartStack<T>::Peek()
	{
		return mStack.top();
	}

	template<typename T>
	inline T SmartStack<T>::GetMax()
	{
		if (mTotalSize == 0)
		{
			return numeric_limits<T>::lowest();
		}
		return mMaxStack.top();
	}

	template<typename T>
	inline T SmartStack<T>::GetMin()
	{
		if (mTotalSize == 0)
		{
			return numeric_limits<T>::max();
		}

		return mMinStack.top();
	}

	template<typename T>
	inline double SmartStack<T>::GetAverage()
	{
		return round((mSum / mTotalSize) * 1000.0) / 1000.0;
	}

	template<typename T>
	inline T SmartStack<T>::GetSum()
	{
		return static_cast<T>(mSum);
	}

	template<typename T>
	inline double SmartStack<T>::GetVariance()
	{
		if (mTotalSize == 0)
		{
			return 0.0;
		}
		double result = (mExSum / mTotalSize) - pow(mSum / mTotalSize, 2);
		return round(result * 1000.0) / 1000.0;
	}

	template<typename T>
	inline double SmartStack<T>::GetStandardDeviation()
	{
		if (mTotalSize == 0)
		{
			return 0.0;
		}
		double result = (mExSum / mTotalSize) - pow(mSum / mTotalSize, 2);
		return round(sqrt(result) * 1000.0) / 1000.0;
	}

	template<typename T>
	inline const unsigned int& SmartStack<T>::GetCount()
	{
		return mTotalSize;
	}

}