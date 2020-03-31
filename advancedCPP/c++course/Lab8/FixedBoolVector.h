#pragma once
#include <cstdint>

using namespace std;
namespace lab8
{
	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		bool Add(bool b);
		bool Remove(bool b);
		bool Get(unsigned int index) const;
		bool operator[](unsigned int index);
		int GetIndex(bool b) const;
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		int32_t mArray[(N / 32) + 1];
		size_t mSize;
	};

	template<size_t N>
	FixedVector<bool, N>::FixedVector()
		: mSize(0)
	{
	}

	template<size_t N>
	bool FixedVector<bool, N>::Add(bool b)
	{
		if (mSize >= N)
		{
			return false;
		}

		int32_t bit = 1 << (mSize % 32);
		if (b)
		{
			mArray[mSize / 32] |= bit;
		}
		else
		{
			mArray[mSize / 32] &= ~bit;
		}
		
		mSize++;
		return true;
	}

	template<size_t N>
	bool FixedVector<bool, N>::Get(unsigned int index) const
	{
		int32_t bit = 1 << (index % 32);
		return mArray[index / 32] & bit;
	}

	template<size_t N>
	bool FixedVector<bool, N>::Remove(bool b)
	{
		if (mSize == 0)
		{
			return false;
		}
		bool bSuccess = false;
		bool bTmp;
		bool bB;
		for (size_t i = 0; i < mSize; i++)
		{
			int32_t bitToCompare = 1 << (i % 32);
			if (!bSuccess)
			{
				bB = (b == true ? (mArray[i / 32] & bitToCompare) : !(mArray[i / 32] & bitToCompare));
				if (bB)
				{
					bSuccess = true;
				}
			}

			if (bSuccess)
			{
				bTmp = (i == mSize - 1 ? false : Get(i + 1));
				int32_t bitToCompare2 = 1 << (i % 32);
				if (bTmp)
				{
					mArray[i / 32] |= bitToCompare;
				}
				else
				{
					mArray[i / 32] &= ~bitToCompare;
				}
			}

		}

		if (bSuccess)
		{
			mSize--;
		}
		return bSuccess;
	}

	template<size_t N>
	bool FixedVector<bool, N>::operator[](unsigned int index)
	{
		int32_t bit = 1 << (index % 32);
		return mArray[index / 32] & bit;
	}

	template<size_t N>
	int FixedVector<bool, N>::GetIndex(bool b) const
	{
		bool bB;
		int32_t tmp;
		for (size_t i = 0; i < mSize; i++)
		{
			tmp = 1 << (i % 32);
			bB = (b == true ? (mArray[i / 32] & tmp) : !(mArray[i / 32] & tmp));
			if (bB)
			{
				return i;
			}
		}
		return -1;
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetSize() const
	{
		return mSize;
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetCapacity() const
	{
		return N;
	}

}
