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

	vector<int> bstToVector(BinaryNode<T>* root)
	{
		vector<int> bst_vect;
		vector<int> result;
		BinaryNode<T>* current = root;

		if (current == nullptr)
		{
			return bst_vect;
		}

		//left
		result = bstToVector(current->left);

		//us
		bst_vect.push_back(current->value);

		//right
		result = bstToVector(current->right);

		// maybe add another return bst_vect? with what if statement? gets caught after left(0) finishes

		/*if (current->right == nullptr)
		{
			return bst_vect;
		}
		else
		{
			bst_vect = bstToVector(current->right);
		}*/
		
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
