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

		std::shared_ptr<Node<T>> mRoot;
		unsigned int mLength;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: mRoot(std::make_unique<Node<T>>(nullptr))
		, mLength(0)
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		std::shared_ptr<Node<T>> node = std::make_shared<Node<T>>(std::move(data));

		Node<T>* nodeRawPtr = node.get();

		std::shared_ptr<Node<T>> lastNode = mRoot;

		Node<T>* lastNodeRawPtr = mRoot.get();

		while (lastNodeRawPtr->Next != nullptr)
		{
			lastNode = lastNodeRawPtr->Next;

			lastNodeRawPtr = lastNode.get();
		}

		lastNodeRawPtr->Next = node;

		nodeRawPtr->Previous = std::weak_ptr<Node<T>>(lastNode);

		++mLength;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		if (index >= mLength)
		{
			Insert(std::move(data));
		}

		std::shared_ptr<Node<T>> node = std::make_shared<Node<T>>(std::move(data));

		Node<T>* nodeRawPtr = node.get();

		Node<T>* lastNodeRawPtr = mRoot.get();

		std::shared_ptr<Node<T>> lastNode = lastNodeRawPtr->Next;

		while (index != 0)
		{
			lastNodeRawPtr = lastNode.get();

			lastNode = lastNodeRawPtr->Next;

			--index;
		}

		lastNodeRawPtr = lastNode.get();

		if (!lastNodeRawPtr->Previous.expired())
		{
			std::shared_ptr<Node<T>> prevNode = lastNodeRawPtr->Previous.lock();
			Node<T>* prevNodeRawPtr = prevNode.get();

			std::shared_ptr<Node<T>> nextNode = lastNodeRawPtr->Next;
			Node<T>* nextNodeRawPtr = nextNode.get();

			nextNodeRawPtr->Previous = std::weak_ptr(lastNode);

			prevNodeRawPtr->Next = node;

			nodeRawPtr->Next = lastNode;

			nodeRawPtr->Previous = std::weak_ptr(prevNode);

			++mLength;
		}
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		Node<T>* lastNodeRawPtr = mRoot.get();

		std::shared_ptr<Node<T>> lastNode = lastNodeRawPtr->Next;

		auto index = mLength;

		while (index != 0)
		{
			lastNodeRawPtr = lastNode.get();

			if (*(lastNodeRawPtr->Data) == data)
			{
				if (!lastNodeRawPtr->Previous.expired())
				{
					std::shared_ptr<Node<T>> prevNode = lastNodeRawPtr->Previous.lock();
					Node<T>* prevNodeRawPtr = prevNode.get();

					std::shared_ptr<Node<T>> nextNode = lastNodeRawPtr->Next;
					Node<T>* nextNodeRawPtr = nextNode.get();

					nextNodeRawPtr->Previous = std::weak_ptr(prevNode);

					prevNodeRawPtr->Next = nextNode;

					lastNodeRawPtr->Data = 0;
					lastNodeRawPtr->Previous = std::weak_ptr<Node<T>>();
					lastNodeRawPtr->Next = nullptr;

					--mLength;

					return true;
				}
			}

			--index;

			lastNode = lastNodeRawPtr->Next;
		}

		return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		Node<T>* lastNodeRawPtr = mRoot.get();

		std::shared_ptr<Node<T>> lastNode = lastNodeRawPtr->Next;

		auto index = mLength;

		while (index != 0)
		{
			lastNodeRawPtr = lastNode.get();

			if (*(lastNodeRawPtr->Data) == data)
			{
				return true;
			}

			lastNode = lastNodeRawPtr->Next;

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

		Node<T>* lastNodeRawPtr = mRoot.get();

		std::shared_ptr<Node<T>> lastNode = lastNodeRawPtr->Next;

		while (index != 0)
		{
			lastNodeRawPtr = lastNode.get();

			lastNode = lastNodeRawPtr->Next;

			--index;
		}

		return lastNode;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mLength;
	}
}