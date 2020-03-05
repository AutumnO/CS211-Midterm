#pragma once
#include "BinaryNode.h"

template <typename T>
class BinarySearchTree
{
private:
	BinaryNode<T>* _root = nullptr;

public:
	BinaryNode<T>* get_root()
	{
		return _root;
	}

	bool exists_iter(BinaryNode<T>* root, int value)
	{
		BinaryNode<T>* current = root;
		while (current != nullptr)
		{
			if (current->value < value)
			{
				current = current->right;
			}
			else if (current->value < value)
			{
				current = current->left;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	bool exists_rec(BinaryNode<T>* root, int value)
	{
		BinaryNode<T>* current = root;
		if (current == nullptr)
		{
			return false;
		}
		if (current->value < value)
		{
			bool result = exists_rec(current->right, value);
		}
		else if (current->value > value)
		{
			current = current->left;
		}
		else
		{
			return true;
		}
	}


	BinaryNode<T>* addElementRec(BinaryNode<T>* node, const T& value)
	{
		//base case
		if (node == nullptr)
		{
			return new BinaryNode<T>{ value };
		}

		//where does the value belong?
		if (value >= node->value)
		{
			BinaryNode<T>* result = addElementRec(node->right, value);
			node->right = result;
		}
		else
		{
			BinaryNode<T>* result = addElementRec(node->left, value);
			node->left = result;
		}
		return node;
	}
	void addElementRec(const T& value)
	{
		_root = addElementRec(_root, value);
	}
};
