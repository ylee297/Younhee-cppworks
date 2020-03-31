#pragma once

namespace lab8
{
	template<class T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		bool Add(const T& t);
		bool Remove(T t);
		const T& Get(unsigned int index);
		T& operator[](unsigned int index);
		int GetIndex(T t) const;
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		T mArray[N];
		size_t mSize;
	};

	template<class T, size_t N>
	FixedVector<T, N>::FixedVector()
		:	mSize(0)
	{
	}

	template<class T, size_t N>
	bool FixedVector<T, N>::Add(const T& t)
	{
		if (mSize == N)
		{
			return false;
		}
		mArray[mSize++] = t;
		return true;
	}

	template<class T, size_t N>
	const T& FixedVector<T, N>::Get(unsigned int index)
	{
		return mArray[index];
	}

	template<class T, size_t N>
	bool FixedVector<T, N>::Remove(T t)
	{
		bool bFound = false;
		for (size_t i = 0; i < mSize; i++)
		{
			if (mArray[i] == t)
			{
				bFound = true;
			}

			if (bFound)
			{
				if (i != mSize - 1)
				{
					mArray[i] = mArray[i + 1];
				}
				else
				{
					mArray[i] = NULL;
				}
			}
		}

		if (bFound)
		{
			mSize--;
		}
		return bFound;
	}

	template<class T, size_t N>
	T& FixedVector<T, N>::operator[](unsigned int index)
	{
		return mArray[index];
	}

	template<class T, size_t N>
	int FixedVector<T, N>::GetIndex(T t) const
	{
		for (int i = 0; i < int(mSize); i++)
		{
			if (mArray[i] == t)
			{
				return i;
			}
		}
		return -1;
	}

	template<class T, size_t N>
	size_t FixedVector<T, N>::GetSize() const
	{
		return mSize;
	}

	template<class T, size_t N>
	size_t FixedVector<T, N>::GetCapacity() const
	{
		return N;
	}


}
