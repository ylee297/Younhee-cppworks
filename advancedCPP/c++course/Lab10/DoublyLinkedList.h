#pragma once
#include <memory>
#include "Node.h"
namespace lab10
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;
	private:
		std::shared_ptr<Node<T>> mFirstNode;
		unsigned int mLength;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		:	mLength(0)
	{
		mFirstNode = nullptr;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		if (mLength == 0)
		{
			mFirstNode = std::make_shared<Node<T>>(std::move(data));
			mLength++;
			return;
		}

		std::shared_ptr<Node<T>> tmp(mFirstNode);

		while (tmp->Next != nullptr)
		{
			tmp = tmp->Next;
		}
		tmp->Next = std::make_shared<Node<T>>(std::move(data), tmp);
		mLength++;
		tmp = nullptr;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		if (index >= mLength)
		{
			Insert(std::move(data));
			return;
		}

		if (mFirstNode == nullptr)
		{
			mFirstNode = std::make_shared<Node<T>>(std::move(data));
			mLength++;
			return;
		}

		std::shared_ptr<Node<T>> tmp(mFirstNode);
		for (unsigned int i = 0; i + 1 < index; i++)
		{
			tmp = tmp->Next;
		}

		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data));
	
		if (index > 0)
		{
			newNode->Next = tmp->Next;
			tmp->Next = newNode;
			newNode->Previous = tmp;
		}
		else
		{
			newNode->Next = tmp;
			mFirstNode = newNode;
		}

		if (newNode->Next != nullptr)
		{
			newNode->Next->Previous = newNode;
		}

		mLength++;
		tmp = nullptr;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		if (mFirstNode == nullptr)
		{
			return false;
		}

		if (*mFirstNode->Data == data)
		{
			mFirstNode = mFirstNode->Next;
			mLength--;
			return true;
		}
		
		std::shared_ptr<Node<T>> beforeDel = mFirstNode;
		
		for (unsigned int i = 0; i + 1 < mLength; i++)
		{
			if (i + 2 == mLength)
			{
				if (*beforeDel->Next->Data == data)
				{
					beforeDel->Next = nullptr;
					mLength--;
					return true;
				}
				break;
			}

			if (*beforeDel->Next->Data == data)
			{
				beforeDel->Next = beforeDel->Next->Next;
				beforeDel->Next->Previous = beforeDel;
				mLength--;
				return true;;
			}

			beforeDel = beforeDel->Next;
		}
		
		beforeDel = nullptr;
		return false;


		//std::shared_ptr<Node<T>> tmp(mFirstNode);
		//std::shared_ptr<Node<T>> tmp2(mFirstNode);
		//if (tmp != nullptr && *tmp->Data == data)
		//{
		//	mFirstNode = tmp->Next;
		//	//tmp->Next->Previous = nullptr;
		//	tmp = nullptr;
		//	tmp2 = nullptr;
		//	mLength--;
		//	return true;
		//}

		//while (tmp != nullptr)
		//{
		//	if (*tmp->Data == data)
		//	{
		//		tmp2->Next = tmp->Next;
		//		//tmp->Next->Previous = tmp2;
		//		tmp = nullptr;
		//		tmp2 = nullptr;
		//		mLength--;
		//		return true;
		//	}
		//	tmp2 = tmp;
		//	tmp = tmp->Next;
		//}

		//tmp = nullptr;
		//tmp2 = nullptr;
		//return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		std::shared_ptr<Node<T>> tmp(mFirstNode);
		while (tmp != nullptr)
		{
			if (*(tmp->Data) == data)
			{
				tmp = nullptr;
				return true;
			}
			tmp = tmp->Next;
		}
		return false;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		std::shared_ptr<Node<T>> result(mFirstNode);
		for (unsigned int i = 0; i < index; i++)
		{
			if (index >= mLength)
			{
				return nullptr;
			}
			result = result->Next;
		}
		return result;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mLength;
	}
}