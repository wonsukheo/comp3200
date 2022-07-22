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

		std::shared_ptr<Node<T>> Root;
		unsigned int mLength;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: Root()
		, mLength(0)
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		if (mLength == 0)
		{
			Root = std::make_shared<Node<T>>(std::move(data));
		}
		else
		{
			std::shared_ptr<Node<T>> currentNode = Root;

			Node<T>* rawPtr = Root.get();

			while (rawPtr->Next != nullptr)
			{
				currentNode = rawPtr->Next;

				rawPtr = currentNode.get();
			}

			std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data), currentNode);

			rawPtr->Next = newNode;
		}

		++mLength;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		if (index >= mLength)
		{
			return Insert(std::move(data));
		}

		std::shared_ptr<Node<T>> currentNode = Root;

		Node<T>* rawPtr = Root.get();

		if (index == 0)
		{
			std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data));

			Node<T>* newNodeRawPtr = newNode.get();

			newNodeRawPtr->Next = currentNode;

			rawPtr->Previous = std::weak_ptr<Node<T>>(newNode);

			Root = newNode;


			++mLength;

			return;
		}

		while (index != 0)
		{
			currentNode = rawPtr->Next;

			rawPtr = currentNode.get();

			--index;
		}

		std::shared_ptr<Node<T>> prevNode = rawPtr->Previous.lock();

		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data), prevNode);

		Node<T>* newNodeRawPtr = newNode.get();

		newNodeRawPtr->Next = currentNode;
		
		Node<T>* prevNodeRawPtr = prevNode.get();

		prevNodeRawPtr->Next = newNode;

		rawPtr->Previous = std::weak_ptr<Node<T>>(newNode);

		++mLength;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		std::shared_ptr<Node<T>> currentNode = Root;

		auto index = mLength;

		while (index != 0)
		{
			Node<T>* rawPtr = currentNode.get();

			if (*(rawPtr->Data) == data)
			{
				if (index == mLength)
				{
					if (rawPtr->Next == nullptr)
					{
						Root = nullptr;
					}
					else
					{
						std::shared_ptr<Node<T>> nextNode = rawPtr->Next;

						Node<T>* rawPtr = nextNode.get();

						rawPtr->Previous = std::weak_ptr<Node<T>>();

						Root = nextNode;
					}
				}
				else if (index == 1)
				{
					std::shared_ptr<Node<T>> prevNode = rawPtr->Previous.lock();
					Node<T>* prevRawPtr = prevNode.get();

					prevRawPtr->Next = nullptr;

					prevNode = nullptr; // not sure if needed
				}
				else
				{
					std::shared_ptr<Node<T>> prevNode = rawPtr->Previous.lock();
					Node<T>* prevRawPtr = prevNode.get();

					std::shared_ptr<Node<T>> nextNode = rawPtr->Next;
					Node<T>* nextRawPtr = nextNode.get();

					prevRawPtr->Next = rawPtr->Next;

					nextRawPtr->Previous = rawPtr->Previous;
				}

				--mLength;
				return true;
			}

			currentNode = rawPtr->Next;

			--index;
		}

		return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		std::shared_ptr<Node<T>> currentNode = Root;

		Node<T>* rawPtr;

		auto index = mLength;

		while (index != 0)
		{
			rawPtr = currentNode.get();

			if (*(rawPtr->Data) == data)
			{
				return true;
			}

			currentNode = rawPtr->Next;

			--index;
		}

		return false;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		if (index >= mLength)
		{
			return nullptr;
		}

		std::shared_ptr<Node<T>> currentNode = Root;

		Node<T>* rawPtr = Root.get();
		
		while (index != 0)
		{
			currentNode = rawPtr->Next;

			rawPtr = currentNode.get();

			--index;
		}

		return currentNode;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mLength;
	}
}