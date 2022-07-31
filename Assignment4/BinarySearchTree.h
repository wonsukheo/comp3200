#pragma once

#include <memory>
#include <vector>

namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);
		static void TraverseRecursive(const std::shared_ptr<TreeNode<T>> node, std::vector<T>* list);

	private:
		std::shared_ptr<TreeNode<T>> mRoot;
	};

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		std::shared_ptr<TreeNode<T>>* lastNode = &mRoot;

		std::shared_ptr<TreeNode<T>>* previousNode = nullptr;

		while (*lastNode != nullptr)
		{
			previousNode = lastNode;

			lastNode = (*data <= *(*lastNode)->Data) ? &(*lastNode)->Left : &(*lastNode)->Right;
		}

		std::unique_ptr<TreeNode<T>> temp = previousNode == nullptr ?
			std::make_unique<TreeNode<T>>(std::move(data)) : std::make_unique<TreeNode<T>>(*previousNode, std::move(data));

		*lastNode = std::move(temp);
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		return mRoot;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		std::shared_ptr<TreeNode<T>> nodeIter = mRoot;

		while (nodeIter != nullptr)
		{
			if (data == *nodeIter->Data)
			{
				return true;
			}

			nodeIter = (data <= *nodeIter->Data) ? nodeIter->Left : nodeIter->Right;
		}

		return false;
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		std::shared_ptr<TreeNode<T>> nodeIter = mRoot;
		std::shared_ptr<TreeNode<T>> previousNode;
		std::shared_ptr<TreeNode<T>> dataNode;
		//no nodes
		if (mRoot == nullptr)
		{
			return false;
		} 
		//find data node
		while (nodeIter != nullptr)
		{
			if (data == *nodeIter->Data)
			{
				dataNode = nodeIter;

				break;
			}

			previousNode = nodeIter;

			nodeIter = (data <= *nodeIter->Data) ? nodeIter->Left : nodeIter->Right;
		}
		// no matching data
		if (dataNode == nullptr)
		{
			return false;
		} 
		//no leaf
		if (dataNode->Left == nullptr && dataNode->Right == nullptr)
		{
			if (previousNode == nullptr)
			{
				mRoot = nullptr;
				return true;
			}

			if (previousNode->Left == dataNode)
			{
				previousNode->Left = nullptr;
			}
			else
			{
				previousNode->Right = nullptr;
			}

			return true;
		} 

		if (dataNode->Left != nullptr && dataNode->Right != nullptr)
		{
			std::shared_ptr<TreeNode<T>> replaceNode = dataNode->Right;
			std::shared_ptr<TreeNode<T>> prevToReplaceNode = dataNode;
			//find replace node
			while (replaceNode->Left != nullptr)
			{
				prevToReplaceNode = replaceNode;

				replaceNode = replaceNode->Left;
			}

			if (previousNode == nullptr)
			{
				if (prevToReplaceNode != dataNode)
				{
					prevToReplaceNode->Left = replaceNode->Right;
				}

				replaceNode->Left = dataNode->Left;
				replaceNode->Right = dataNode->Right;

				mRoot = replaceNode;
				return true;
			}

			if (previousNode->Left == dataNode)
			{
				if (prevToReplaceNode != dataNode)
				{
					prevToReplaceNode->Left = replaceNode->Right;
				}

				replaceNode->Left = dataNode->Left;

				if (dataNode->Right != replaceNode)
				{
					replaceNode->Right = dataNode->Right;
				}

				previousNode->Left = replaceNode;
			}
			else
			{
				if (prevToReplaceNode != dataNode)
				{
					prevToReplaceNode->Left = replaceNode->Right;
				}

				replaceNode->Left = dataNode->Left;

				if (dataNode->Right != replaceNode)
				{
					replaceNode->Right = dataNode->Right;
				}

				previousNode->Right = replaceNode;
			}

			return true;
		}

		if (previousNode == nullptr)
		{
			mRoot = dataNode->Left == nullptr ? dataNode->Right : dataNode->Left;

			return true;
		}

		if (previousNode->Left == dataNode)
		{
			previousNode->Left = dataNode->Left == nullptr ? dataNode->Right : dataNode->Left;

			return true;
		}
		else
		{
			previousNode->Right = dataNode->Left == nullptr ? dataNode->Right : dataNode->Left;

			return true;
		}

		return false;
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> temp;

		TraverseRecursive(startNode, &temp);

		return temp;
	}


	template<typename T>
	void BinarySearchTree<T>::TraverseRecursive(const std::shared_ptr<TreeNode<T>> node, std::vector<T>* list)
	{
		if (node == nullptr)
		{
			return;
		}

		if (node->Left != nullptr)
		{
			TraverseRecursive(node->Left, list);
		}

		if (node->Right != nullptr)
		{
			TraverseRecursive(node->Right, list);
		}


		if (list->empty())
		{
			list->push_back(*node->Data);
			return;
		}

		for (typename std::vector<T>::iterator iter = list->begin(); iter != list->end(); ++iter)
		{
			if (*node->Data <= *iter)
			{
				list->insert(iter, *node->Data);
				break;
			}
			else if (iter == list->end() - 1)
			{
				list->push_back(*node->Data);
				break;
			}
		}
	}
}