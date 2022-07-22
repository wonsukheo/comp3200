#pragma once

#include <memory>

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
		
		std::shared_ptr<Node<T>> Root;
		unsigned int mLength;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: mLength(0)
		, Root()
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		std::shared_ptr<Node<T>> lastNode = Root;

		if (lastNode == nullptr)
		{
			Root = std::make_shared<Node<T>>(std::move(data));

			++mLength;

			return;
		}

		while (lastNode->Next != nullptr)
		{
			lastNode = lastNode->Next;
		}

		lastNode->Next = std::make_shared<Node<T>>(std::move(data), lastNode);

		++mLength;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		if (index >= mLength)
		{
			Insert(std::move(data));
			return;
		}

		std::shared_ptr<Node<T>> indexNode = Root;

		if (indexNode == nullptr)
		{
			Root = std::make_shared<Node<T>>(std::move(data));

			++mLength;
			return;
		}

		if (index == 0)
		{
			std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data));

			newNode->Next = Root;

			Root->Previous = newNode;

			Root = newNode;

			++mLength;
			return;
		}

		while (index-- != 0)
		{
			indexNode = indexNode->Next;
		}
		
		std::shared_ptr<Node<T>> prevNode = indexNode->Previous.lock();

		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data), prevNode);

		newNode->Next = indexNode;

		prevNode->Next = newNode;

		indexNode->Previous = newNode;

		++mLength;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		std::shared_ptr<Node<T>> nodeIter = Root;
		
		if (mLength == 0)
		{
			return false;
		}

		while (true)
		{
			if (*(nodeIter->Data) == data)
			{
				std::shared_ptr<Node<T>> prevNode = nodeIter->Previous.lock();
				std::shared_ptr<Node<T>> nextNode = nodeIter->Next;

				if (prevNode == nullptr)
				{
					Root = nextNode;

					--mLength;
					return true;
				}

				if (nextNode == nullptr)
				{
					prevNode->Next = nullptr;

					--mLength;
					return true;
				}

				prevNode->Next = nextNode;

				nextNode->Previous = prevNode;

				--mLength;
				return true;
			}
			
			if (nodeIter->Next == nullptr)
			{
				return false;
			}

			nodeIter = nodeIter->Next;
		}
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		std::shared_ptr<Node<T>> nodeIter = Root;

		if (mLength == 0)
		{
			return false;
		}

		while (true)
		{
			if (*(nodeIter->Data) == data)
			{
				return true;
			}

			if (nodeIter->Next == nullptr)
			{
				return false;
			}

			nodeIter = nodeIter->Next;
		}
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		if (index >= mLength)
		{
			return nullptr;
		}

		std::shared_ptr<Node<T>> indexNode = Root;

		while (index-- != 0)
		{
			indexNode = indexNode->Next;
		}

		return indexNode;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mLength;
	}
}