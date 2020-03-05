#pragma once
#include "BinaryNode.h"
#include <vector>
using namespace std;

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
