#pragma once
#include <queue>

namespace lab9
{
	template <class T>
	class ObjectPool
	{
	public:
		ObjectPool(size_t maxPoolSize);
		~ObjectPool();
		ObjectPool(const ObjectPool& obj) = delete;
		ObjectPool& operator=(const ObjectPool& obj) = delete;
		size_t GetFreeObjectCount();
		size_t GetMaxFreeObjectCount();

		T* Get();
		void Return(T* t);
	private:
		std::queue<T*> mObjects;
		size_t mMaxPoolSize;
		size_t mSize;
	};

	template <class T>
	inline ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: mSize(0), mMaxPoolSize(maxPoolSize)
	{
	}

	template <class T>
	inline ObjectPool<T>::~ObjectPool()
	{
		for (unsigned int i = 0; i < mSize; i++)
		{
			delete mObjects.front();
			mObjects.pop();
		}
	}

	template <class T>
	inline T* ObjectPool<T>::Get()
	{
		if (mSize == 0)
		{
			T* tmp2 = new T();
			return tmp2;
		}

		T* tmp = mObjects.front();
		mObjects.pop();
		mSize--;
		return tmp;
	}

	template <class T>
	inline void ObjectPool<T>::Return(T* t)
	{
		if (mSize == mMaxPoolSize)
		{
			delete t;
			return;
		}
		mObjects.push(t);
		mSize++;
	}

	template <class T>
	inline size_t ObjectPool<T>::GetFreeObjectCount()
	{
		return mSize;
	}

	template <class T>
	inline size_t ObjectPool<T>::GetMaxFreeObjectCount()
	{
		return mMaxPoolSize;
	}
}
