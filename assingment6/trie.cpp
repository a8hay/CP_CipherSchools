#include <bits/stdc++.h>
using namespace std;

#define CHARSIZE 26

class TrieNode
{
public:
	bool isWord;
	TrieNode* children[CHARSIZE];

	TrieNode()
	{
		this->isWord = false;
		for(int i=0; i<CHARSIZE; i++)
		{
			this->children[i] = NULL;
		}
	}
}

class Trie
{
public:
	TrieNode *root;
	Trie()
	{
		this->root = NULL;
	}

	void insert(string str)
	{
		TrieNode *crawler = this->root;
		for (int i=0; i<str.size(); i++)
		{
			if (crawler->children[str[i] - 'A'] == NULL)
			{
				// create a child
				crawler->children[str[i] - 'A'] = new TrieNode();
			}
			crawler = crawler->children[str[i] - 'A'];
		}
		crawler->isWord = true;
	}

	// preorder traversal
	void printDictionaryHelper(TrieNode *crawler, string &str)
	{
		
	}

	void printDictionary()
	{
		TrieNode *crawler = this->root;
		string str = "";
		printDictionaryHelper(crawler, str);
	}
}

int main()
{
	Trie trie;
	trie.insert("DOG");
	trie.insert("CAT");
	trie.insert("DO");
	trie.printDictionary();
	return 0;
}