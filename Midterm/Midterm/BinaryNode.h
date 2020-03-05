#pragma once


template <typename T>
class BinaryNode {
public:
	int value = -1;
	BinaryNode* left = nullptr;
	BinaryNode* right = nullptr;

	BinaryNode(const T& value)
		: value(value) {}

	BinaryNode() {}

	bool exists_iter(BinaryNode* root, int value)
	{

	}

	bool exists_rec(BinaryNode* root, int value)
	{
		
		if (node == nullptr)
		{
			return false;
		}
		if (node->value < value)
		{
			bool result = exists_rec(node->right, value);
		}
		else if (node->value > value)
		{
			node = node->left;
		}
		else
		{
			return true;
		}
	}
};