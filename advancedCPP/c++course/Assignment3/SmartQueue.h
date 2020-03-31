#pragma once
#include <queue>
#include <cmath>
#include <limits>

using namespace std;

namespace assignment3
{
	template<typename T>
	class SmartQueue
	{
	private:
		queue<T> mQueue;
		unsigned int mTotalSize;
		double mSum;
		double mExSum;
	public:
		SmartQueue();
		~SmartQueue();
		void Enqueue(T a);
		T Dequeue();
		T Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount();
	};


	template<typename T>
	inline SmartQueue<T>::SmartQueue()
		:	mSum(0), mTotalSize(0), mExSum(0)
	{
	}

	template<typename T>
	inline SmartQueue<T>::~SmartQueue()
	{
	}

	template<typename T>
	inline void SmartQueue<T>::Enqueue(T a)
	{
		mSum += a;
		mExSum += pow(a, 2);
		mTotalSize++;
		mQueue.push(a);
	}

	template<typename T>
	inline T SmartQueue<T>::Dequeue()
	{
		T a = mQueue.front();
		mExSum -= pow(a, 2);
		mSum -= a;
		mTotalSize--;
		mQueue.pop();
		return a;
	}

	template<typename T>
	inline T SmartQueue<T>::Peek()
	{
		return mQueue.front();
	}

	template<typename T>
	inline T SmartQueue<T>::GetMax()
	{
		T max = numeric_limits<T>::lowest();
		queue<T> tmpQueue;
		for (unsigned int i = 0; i < mTotalSize; i++)
		{
			T tmp = mQueue.front();
			tmpQueue.push(tmp);
			mQueue.pop();
			if (tmp > max)
			{
				max = tmp;
			}
		}

		swap(mQueue, tmpQueue);
		return max;
	}

	template<typename T>
	inline T SmartQueue<T>::GetMin()
	{
		queue<T> tmpQueue;
		T min = numeric_limits<T>::max();
		for (unsigned int i = 0; i < mTotalSize; i++)
		{
			T tmp = mQueue.front();
			tmpQueue.push(tmp);
			mQueue.pop();
			if (tmp < min)
			{
				min = tmp;
			}
		}

		swap(mQueue, tmpQueue);
		return min;
	}

	template<typename T>
	inline double SmartQueue<T>::GetAverage()
	{
		//double average = double(GetSum());
		//average = round((average / mTotalSize) * 1000.0) / 1000.0;
		//return average;
		return round((mSum / mTotalSize) * 1000.0) / 1000.0;
	}

	template<typename T>
	inline T SmartQueue<T>::GetSum()
	{
		return static_cast<T>(mSum);
	}

	template<typename T>
	inline double SmartQueue<T>::GetVariance()
	{
		double result = (mExSum / mTotalSize) - pow(mSum / mTotalSize, 2);
		return round(result * 1000.0) / 1000.0;
	}

	template<typename T>
	inline double SmartQueue<T>::GetStandardDeviation()
	{
		double result = (mExSum / mTotalSize) - pow(mSum / mTotalSize, 2);
		result = sqrt(result);
		return round(result * 1000.0) / 1000.0;
	}

	template<typename T>
	inline unsigned int SmartQueue<T>::GetCount()
	{
		return mTotalSize;
	}
}