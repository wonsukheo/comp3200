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
		std::shared_ptr<Node<T>> currentNode = mRoot;

		Node<T>* rawPtr = mRoot.get();
		
		while (rawPtr->Next != nullptr)
		{
			currentNode = rawPtr->Next;

			rawPtr = currentNode.get();
		}

		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data), currentNode);

		rawPtr->Next = newNode;

		++mLength;
		
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		if (index >= mLength)
		{
			return Insert(std::move(data));
		}

		Node<T>* rawPtr = mRoot.get();

		std::shared_ptr<Node<T>> currentNode = rawPtr->Next;

		rawPtr = currentNode.get();

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
		Node<T>* rawPtr = mRoot.get();

		std::shared_ptr<Node<T>> nodeIter = rawPtr->Next;

		auto index = mLength;

		while (index != 0)
		{
			rawPtr = nodeIter.get();

			if (*(rawPtr->Data) == data)
			{
				if (rawPtr->Next == nullptr)
				{
					std::shared_ptr<Node<T>> prevNode = rawPtr->Previous.lock();
					Node<T>* prevRawPtr = prevNode.get();

					prevRawPtr->Next = nullptr;
				}
				else
				{
					std::shared_ptr<Node<T>> prevNode = rawPtr->Previous.lock();
					Node<T>* prevRawPtr = prevNode.get();

					std::shared_ptr<Node<T>> nextNode = rawPtr->Next;
					Node<T>* nextRawPtr = nextNode.get();

					prevRawPtr->Next = rawPtr->Next;

					nextRawPtr->Previous = std::weak_ptr<Node<T>>(prevNode);
				}

				--mLength;
				return true;
			}

			nodeIter = rawPtr->Next;

			--index;
		}

		return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		Node<T>* rawPtr = mRoot.get();

		std::shared_ptr<Node<T>> nodeIter = rawPtr->Next;

		auto index = mLength;

		while (index != 0)
		{
			rawPtr = nodeIter.get();

			if (*(rawPtr->Data) == data)
			{
				return true;
			}

			nodeIter = rawPtr->Next;

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

		Node<T>* rawPtr = mRoot.get();

		std::shared_ptr<Node<T>> nodeIter = rawPtr->Next;
		
		while (index != 0)
		{
			rawPtr = nodeIter.get();

			nodeIter = rawPtr->Next;

			--index;
		}

		return nodeIter;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mLength;
	}
}