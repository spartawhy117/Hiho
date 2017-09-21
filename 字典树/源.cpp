#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int ALPHABET_SIZE=26;


struct TrieNode
{
	int _count;
	TrieNode* _child[ALPHABET_SIZE];
	TrieNode()
	{
		_count = 0;
		for (int i = 0; i<ALPHABET_SIZE; ++i)
		{
			_child[i] = nullptr;
		}
	}
};

TrieNode* createNode()
{
	TrieNode* pNode = new TrieNode();

	return pNode;
}


void TrieInsert(TrieNode* root,const string& key)
{
	
	TrieNode* _root = root;
	int size = key.size();
	for(int i=0;i<size;i++)
	{
		if(_root->_child[key[i]-'a']==nullptr)
		{
			_root->_child[key[i] - 'a'] = createNode();
			_root->_child[key[i] - 'a']->_count++;

		}
		else
		{
			_root->_child[key[i] - 'a']->_count++;
		}
		_root = _root->_child[key[i] - 'a'];

	}

}
int TrieSearch(TrieNode* root,const string& key)
{
	TrieNode* node = root;
	int index = 0;
	int size = key.size();
	while(index<size&&node!=nullptr)
	{
		node = node->_child[key[index] - 'a'];
		++index;
	}


	if (node == nullptr)
		return 0;
	else
		return node->_count;

}

int main(int argc, char* argv[])
{
	int n;
	cin >>n;
	TrieNode* root=createNode();

	while (n--)
	{
		string str;
		std::cin >> str;
		TrieInsert(root, str);
	}

	int r;
	cin >> r;

	for(int i=0;i<r;++i)
	{
		string str;
		cin >> str;
		cout << TrieSearch(root,str) << endl;
		
	}
	
		
	

	return 0;
}
