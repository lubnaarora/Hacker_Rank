#include<iostream>
#include<vector>

using namespace std;
#define ALPHABET_SIZE 26

struct Trie {
	Trie* child[ALPHABET_SIZE];
	int cnt;

	Trie()
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
			this->child[i] = NULL;
		this->cnt = 0;
	}
};

void insert(Trie*& root, string s)
{
	Trie* curr = root;
	int len = s.size();
	for (int i = 0; i < len; i++)
	{
		int index = s[i] - 'a';
		if (curr->child[index] == NULL)
			curr->child[index] = new Trie();

		curr->child[index]->cnt++;
		curr = curr->child[index];
	}
}

void del(Trie*& root)
{
	if (root == NULL)
		return;

	for (int i = 0; i < 26; i++)
		del(root->child[i]);
	delete root;
}

int find(Trie* root, string s)
{
	Trie* curr = root;
	int len = s.size();
	for (int i = 0; i < len; i++)
	{
		int index = s[i] - 'a';
		if (curr->child[index] == NULL)
			return 0;

		curr = curr->child[index];
	}

	return curr->cnt;
}

vector<int> contacts(vector<vector<string>> q) {
	int n = q.size();
	Trie* root = new Trie();
	int c = 0;
	vector<int> v;
	for (int i = 0; i < n; i++)
		if (q[i][0] == "add")
			insert(root, q[i][1]);
		else if (q[i][0] == "find")
			v.push_back(find(root, q[i][1]));

	del(root);
	return v;
}
