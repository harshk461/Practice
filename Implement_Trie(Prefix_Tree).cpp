#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = 0;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (auto it : word)
        {
            char ch = it;
            node->children[ch - 'a'] = new TrieNode(ch);
            node = node->children[ch - 'a'];
        }
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (auto it : word)
        {
            char ch = it;
            if (node->children[ch - 'a'] == NULL)
                return false;
            node = node->children[ch - 'a'];
        }

        if (node->children[word[word.length() - 1] - 'a']->isTerminal)
            return true;
        return false;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (auto it : word)
        {
            int ch = it - 'a';
            if (node->children[ch] == NULL)
                return false;
            node = node->children[ch];
        }

        return true;
    }
};

int main()
{

    return 0;
}