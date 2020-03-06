#include <string>
#include <vector>
#include <iostream>
#include "BinarySearchTree.h"
#include "Problem_2.h"
using namespace std;


int main()
{
	BinarySearchTree<int> bst{};

	for (int i = 0; i < 10; i++)
	{
		bst.addElementRec(rand() % 100);
	}

	exists_iter(bst.get_root(), 1);
	exists_iter(bst.get_root(), 6);

	vector<int> new_vector = bstToVector(bst.get_root());

	cout << (isAVL(bst.get_root())) << endl;
	cout << (getHeight(bst.get_root()));
	
	return 0;
}