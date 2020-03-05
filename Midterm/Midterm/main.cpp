#include <string>
#include <vector>
#include <iostream>
#include "BinarySearchTree.h"




/* 2A.Write an iterative function that determines whether or not a given value exists within the supplied BST.

2B.Write a recursive function that determines whether or not a given value exists within the supplied BST.
bool exists_rec(BinaryNode * root, int value)

2C.Write a function called bstToVector that converts and returns the supplied binary search tree into a sorted STL vector(HINT #1: a certain traversal makes this much easier.HINT #2: using a recursive helper function may be necessary).
vector<int> bstToVector(BinaryNode * root)

2D.An AVL tree is a tree whose height of left and right subtrees differs by no more than one thereby ensuring balance.Write a function called isAvl that returns true when the supplied tree is AVL compliant.
bool isAVL(BinaryNode * root)

2E.Write a function called getHeight that returns the height of the supplied tree.
int getHeight(BinaryNode * root)
*/

int main()
{
	BinarySearchTree<int> bst{};

	for (int i = 0; i < 10; i++)
	{
		bst.addElementRec(i);
	}

	bst.exists_iter(bst.get_root(), 1);
	bst.exists_iter(bst.get_root(), 6);
	
	return 0;
}