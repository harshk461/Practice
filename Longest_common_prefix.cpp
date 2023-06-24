#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = 0;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // word is in upper case
        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // absent
        else
        {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    // time complexity- O(l) l=length of word
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            if (root->childCount == 1)
            {
                ans.push_back(ch);
                // increment
                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }

            if (root->isTerminal)
            {
                break;
            }
        }
    }
};

// simple approach with O(N^2)
string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";
    for (int i = 0; i < strs[0].length(); i++)
    {
        char ch = strs[0][i];
        bool match = true;

        for (int j = 1; j < strs.size(); j++)
        {
            // not match
            if (ch != strs[j][i])
            {
                match = false;
                break;
            }
        }

        if (match == false)
        {
            break;
        }
        ans.push_back(ch);
    }
    return ans;
}

// Using Tries
string longestCommonPrefix(vector<string> &strs)
{
    Trie *t = new Trie('\0');

    // insert all string in trie
    for (int i = 0; i < strs.size(); i++)
    {
        t->insertWord(word);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);
    return ans;
}

int main()
{

    return 0;
}