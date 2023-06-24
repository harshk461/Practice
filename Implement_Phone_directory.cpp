#include <bits/stdc++.h>
using namespace std;

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
        int index = word[0] - 'a';
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

    void printSuggestion(TrieNode *curr, vector<string> &temp, string prefix)
    {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];

            // if exists
            if (next != NULL)
            {
                prefix.push_back(ch);
                printSuggestion(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str)
    {
        TrieNode *prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.length(); i++)
        {
            char lastch = str[i];

            prefix.push_back(lastch);

            // check for lastch
            TrieNode *curr = prev->children[lastch - 'a'];

            // if not found
            if (curr == NULL)
            {
                break;
            }

            // if found
            vector<string> temp;
            printSuggestion(curr, temp, prefix);

            // store temp
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    // creation of trie
    Trie *t = new Trie();

    // inserting all contact is trie
    for (int i = 0; i < contactList.size(); i++)
    {
        string key = contactList[i];
        t->insertWord(key);
    }
    return t->getSuggestions(queryStr);
}

int main()
{

    return 0;
}