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
};