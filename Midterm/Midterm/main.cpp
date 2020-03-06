#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "BinarySearchTree.h"
#include "Problem_2.h"
#include "LinkedList.h"
using namespace std;

bool isBalanced(string to_evaluate, unordered_map<string, string> braces)
{
	return true;
}

bool has_unique_chars(string text)
{
	unordered_map<char, int> characters{};
	for (int i = 0; i < text.length(); i++)
	{
		characters.insert({ text[i], i });
	}
	
	if (text.size() > characters.size())
	{
		return false;
	}
	else
	{
		return true;
	}
}

string most_common_word(string text)
{
	return "";
}

/* 3. Use a hash table to write a function called isBalanced that determines whether or not the 
provided braces are balanced.E.g. "(ab[cd])" is balanced, "(ab" is not balanced, "(ab[cd)e]" is not balanced.
bool isBalanced(string to_evaluate, unordered_map<string, string> braces)

4. Determine whether or not all characters in a string are unique(HINT: use an unordered_map)
bool has_unique_chars(string text)

5. Determine the most commonly occurring word in a string.  (HINT: use an unordered_map)
string most_common_word(string text)*/

int main()
{
	cout << boolalpha;
	BinarySearchTree<int> bst{};

	for (int i = 0; i < 10; i++)
	{
		bst.addElementRec(rand() % 100);
	}

	exists_iter(bst.get_root(), 1);
	exists_iter(bst.get_root(), 6);

	vector<int> new_vector = bstToVector(bst.get_root());

	cout << (isAVL(bst.get_root())) << endl;
	cout << (getHeight(bst.get_root())) << endl;

	cout << "Should be true: " << (has_unique_chars("abcdefg h")) << endl;
	cout << "Should be false: " << (has_unique_chars("candle baby sick")) << endl;
	cout << "Should be true: " << (has_unique_chars("a")) << endl;
	cout << "Should be false: " << (has_unique_chars("  ")) << endl;
	
	return 0;
}