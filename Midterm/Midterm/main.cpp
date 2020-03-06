#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include "BinarySearchTree.h"
#include "Problem_2.h"
#include "LinkedList.h"
using namespace std;

bool isBalanced(string to_evaluate, unordered_map<string, string> braces)
{
	for (int i = 0; i < to_evaluate.size(); i++)
	{
		if (to_evaluate[i] == '(' || to_evaluate[i] <= ')')
		{

		}
	}
	return true;
}

//				*** Problem 4 ***	O(N)???
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


//					*** Problem 5 ***		O(N)
string most_common_word(string text)
{
	int prev_size;
	string word;
	int most = 0;
	string big_word = text;

	istringstream sin(text);
	unordered_map<string, int> words{};
	while (sin.good() == true)
	{
		sin >> word;
		prev_size = words.size();
		words.insert({ word, 1 });
		if (prev_size == words.size())
		{
			words[word] += 1;
		}
	}

	for (auto value : words)
	{
		if (value.second > most)
		{
			big_word = value.first;
			most = value.second;
		}
	}
	
	return big_word;
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

	cout << "Should be af: " << (most_common_word("af af ba ba cak af")) << endl;
	cout << "Should be caba: " << (most_common_word("caba daf caba")) << endl;
	cout << "Should be a: " << (most_common_word("a")) << endl; 
	cout << "Should be sup: " << (most_common_word("cup bup nup sup sup")) << endl;
	
	return 0;
}