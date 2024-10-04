#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

struct TrieNode
{
    int count = 0;
    TrieNode *children[26] = {};
};

class Trie
{

public:
    Trie()
    {
        TrieNode *root = new TrieNode();
    }

    void insert(string &word)
    {
        TrieNode *node = root;
        for (auto it : word)
        {
            int idx = it - 'a';
            node->children[idx] = new TrieNode();
            node->count++;
            node = node->children[idx];
        }
    }

    int countWordsEqualTo(string &word)
    {
        int ans = 0;
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
    }

    void erase(string &word)
    {
        // Write your code here.
    }
};

int main()
{

    return 0;
}