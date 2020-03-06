#include <vector>
#pragma once
//				*** PROBLEM 2A ***		O(LogN)
template <typename T>
bool exists_iter(BinaryNode<T>* root, int value)
{
	BinaryNode<T>* current = root;
	while (current != nullptr)
	{
		if (current->value < value)
		{
			current = current->right;
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
	return false;
}

//				*** PROBLEM 2B ***		O(LogN)
template <typename T>
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

//				*** PROBLEM 2C ***		O(N)
template <typename T>
vector<int> bstToVector(BinaryNode<T>* root)
{
	vector<int> bst_vect;
	BinaryNode<T>* current = root;


	bst_vect = bstToVectHelper(root, bst_vect);

	return bst_vect;
}

template <typename T>
vector<int> bstToVectHelper(BinaryNode<T>* root, vector<int> bst_vect)
{
	BinaryNode<T>* current = root;

	if (current == nullptr)
	{
		return bst_vect;
	}

	//left
	bst_vect = bstToVectHelper(current->left, bst_vect);

	//right
	bst_vect = bstToVectHelper(current->right, bst_vect);

	//us
	int node_to_push = current->value;
	bst_vect.push_back(node_to_push);

	return bst_vect;
}

//				*** PROBLEM 2D ***		O(N)
template <typename T>
bool isAVL(BinaryNode<T>* root)
{
	BinaryNode<T>* current = root;

	if (current == nullptr)
	{
		return true;
	}

	int left_height = (getHeight(current->left) + 1);
	int right_height = (getHeight(current->right) + 1);

	int dif = right_height - left_height;
	if (dif == 0 || dif == 1 || dif == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//				*** PROBLEM 2E ***		O(N)
template <typename T>
int getHeight(BinaryNode<T>* root)
{
	BinaryNode<T>* current = root;
	if (current == nullptr)
	{
		return 0;
	}
	else
	{
		int left_height = getHeight(current->left);
		int right_height = getHeight(current->right);

		if (left_height > right_height)
		{
			return (left_height + 1);
		}
		else
		{
			return (right_height + 1);
		}
	}

}
/* MIDTERM Question 2
2A.Write an iterative function that determines whether or not a given value exists within the supplied BST.

2B.Write a recursive function that determines whether or not a given value exists within the supplied BST.
bool exists_rec(BinaryNode * root, int value)

2C.Write a function called bstToVector that converts and returns the supplied binary search tree into a sorted STL vector
(HINT #1: a certain traversal makes this much easier.HINT #2: using a recursive helper function may be necessary).
vector<int> bstToVector(BinaryNode * root)

2D.An AVL tree is a tree whose height of left and right subtrees differs by no more than one thereby ensuring balance.
Write a function called isAvl that returns true when the supplied tree is AVL compliant.
bool isAVL(BinaryNode * root)

2E.Write a function called getHeight that returns the height of the supplied tree.
int getHeight(BinaryNode * root)
*/