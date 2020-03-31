#pragma once
#include <queue>
#include <stack>
#include <cmath>
#include <limits>

using namespace std;

namespace assignment3
{
	template<typename T>
	class QueueStack
	{
	private:
		queue<std::stack<T>> mQueueStack;
		unsigned int mStackMaxSize;
		unsigned int mTotalSize;
		double mSum;
		double mExSum;
	public:
		QueueStack(unsigned int size);
		~QueueStack();
		void Enqueue(T a);
		T Dequeue();
		const T& Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		const unsigned int& GetCount();
		unsigned int GetStackCount();
	};

	template<typename T>
	inline QueueStack<T>::QueueStack(unsigned int size)
		:	mStackMaxSize(size), mSum(0), mTotalSize(0), mExSum(0)
	{
	}

	template<typename T>
	inline QueueStack<T>::~QueueStack()
	{
	}

	template<typename T>
	inline void QueueStack<T>::Enqueue(T a)
	{
		mSum += a;
		mExSum += pow(a, 2);
		if (mTotalSize == 0)
		{
			stack<T> tmp;
			mQueueStack.push(tmp);
		}


		if (mQueueStack.back().size() < mStackMaxSize)
		{
			mQueueStack.back().push(a);
		}
		else
		{
			stack<T> tmp;
			mQueueStack.push(tmp);
			mQueueStack.back().push(a);
		}
		mTotalSize++;
	}

	template<typename T>
	inline T QueueStack<T>::Dequeue()
	{
		T a = mQueueStack.front().top();
		mQueueStack.front().pop();
		mSum -= a;
		mExSum -= pow(a, 2);
		if (mQueueStack.front().empty())
		{
			mQueueStack.pop();
		}
		mTotalSize--;
		return a;
	}

	template<typename T>
	inline const T& QueueStack<T>::Peek()
	{
		return mQueueStack.front().top();
	}

	template<typename T>
	inline T QueueStack<T>::GetMax()
	{
		unsigned int size = mQueueStack.size();
		T max = numeric_limits<T>::lowest();
		queue<stack<T>> tmpQueue;
		for (unsigned int i = 0; i < size; i++)
		{
			tmpQueue.push(mQueueStack.front());
			while (!mQueueStack.front().empty())
			{
				if (mQueueStack.front().top() > max)
				{
					max = mQueueStack.front().top();
				}
				mQueueStack.front().pop();
			}
			mQueueStack.pop();
		}

		swap(mQueueStack, tmpQueue);

		return max;
	}

	template<typename T>
	inline T QueueStack<T>::GetMin()
	{
		unsigned int size = mQueueStack.size();
		T min = numeric_limits<T>::max();
		queue<stack<T>> tmpQueue;
		for (unsigned int i = 0; i < size; i++)
		{
			tmpQueue.push(mQueueStack.front());
			while (!mQueueStack.front().empty())
			{
				if (mQueueStack.front().top() < min)
				{
					min = mQueueStack.front().top();
				}
				mQueueStack.front().pop();
			}
			mQueueStack.pop();
		}
		swap(mQueueStack, tmpQueue);

		return min;
	}

	template<typename T>
	inline double QueueStack<T>::GetAverage()
	{
		return round((mSum / mTotalSize) * 1000.0) / 1000.0;
	}

	template<typename T>
	inline T QueueStack<T>::GetSum()
	{
		return static_cast<T>(mSum);
	}

	template<typename T>
	inline double QueueStack<T>::GetVariance()
	{
		if (mTotalSize == 0)
		{
			return 0;
		}
		double result = (mExSum / mTotalSize) - pow(mSum / mTotalSize, 2);
		return round((result) * 1000.0) / 1000.0;
	}

	template<typename T>
	inline double QueueStack<T>::GetStandardDeviation()
	{
		if (mTotalSize == 0)
		{
			return 0;
		}
		double result = (mExSum / mTotalSize) - pow(mSum / mTotalSize, 2);
		result = sqrt(result);
		return round((result) * 1000.0) / 1000.0;
	}

	template<typename T>
	inline unsigned int QueueStack<T>::GetStackCount()
	{
		return mQueueStack.size();
	}

	template<typename T>
	inline const unsigned int& QueueStack<T>::GetCount()
	{
		return mTotalSize;
	}
}