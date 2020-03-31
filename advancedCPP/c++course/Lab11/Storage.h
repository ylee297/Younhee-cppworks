#pragma once
#include <memory>

namespace lab11
{
	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);
		Storage(const Storage<T>& other);
		Storage(Storage<T>&& other);
		 
		Storage<T>& operator=(const Storage<T>& other);
		Storage<T>& operator=(Storage<T>&& other);
		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;
	private:
		unsigned int mLength;
		std::unique_ptr<T[]> mArray;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
		:	mLength(length)
	{
		mArray = std::make_unique<T[]>(mLength);

		/*for (unsigned int i = 0; i < mLength; ++i)
		{
			mArray[i] = 0;
		}*/
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
		:	mLength(length)
	{
		mArray = std::make_unique<T[]>(mLength);

		for (unsigned int i = 0; i < mLength; i++)
		{
			mArray[i] = initialValue;
		}
	}

	template<typename T>
	Storage<T>::Storage(Storage<T>&& other) 
		:	mLength(other.mLength), mArray(std::move(other.mArray))
	{
		other.mLength = 0;
		other.mArray = nullptr;
	}

	template<typename T>
	Storage<T>::Storage(const Storage<T>& other)
		: mLength(other.mLength)
	{
		mArray = std::make_unique<T[]>(mLength);
		for (unsigned int i = 0; i < mLength; i++)
		{
			mArray[i] = other.mArray[i];
		}
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(Storage<T>&& other) 
	{
		if (this != &other)
		{
			mArray = std::move(other.mArray);
			mLength = other.mLength;

			other.mLength = 0;
			other.mArray = nullptr;
		}
		return *this;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(const Storage<T>& other)
	{
		if (this != &other)
		{
			mArray = nullptr;
			mArray = std::make_unique<T[]>(other.mLength);
			mLength = other.mLength;

			for (unsigned int i = 0; i < mLength; i++)
			{
				mArray[i] = other.mArray[i];
			}
			
		}
		return *this;
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index + 1 > mLength)
		{
			return false;
		}
		
		mArray[index] = data;

		return true;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		//std::unique_ptr<T[]> temp = std::make_unique<T[]>(1);
		return mArray;
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mLength;
	}
}