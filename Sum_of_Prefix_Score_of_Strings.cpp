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
    TrieNode *children[26] = {};
    int count = 0; // for counting prefixes;
}

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string &word)
    {
        TrieNode *node = root;
        for (auto it : word)
        {
            int index = it - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();

            node = node->children[index];
            node->count++;
        }
    }

    int getScore(string &word)
    {
        TrieNode *node = root;
        int score = 0;
        for (auto it : word)
        {
            int idx = it - 'a';
            node = node->children[idx];
            score += node->count;
        }

        return score;
    }
};

class Solution
{
private:
    vector<int> brute(vector<string> &words)
    {
        int n = words.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            string word = words[i];
            vector<string> prefixes;
            for (int i = 1; i < word.length(); i++)
                prefixes.push_back(word.substr(0, i));
            int count = 0;
            for (auto prefix : prefixes)
            {
                for (auto i : words)
                {
                    if (prefix == i.substr(0, prefix.length()))
                        count++;
                }
            }

            ans[i] = count;
        }
        return ans;
    }

    vector<int> solve(vector<string> &words)
    {
        multiset<string> ms;

        for (auto word : words)
            for (int i = 1; i <= word.length(); i++)
                ms.insert(word.substr(0, i));

        int n = words.size();
        vector<int> ans(n, 0);

        // for (auto it : map)
        //     cout << it.first << " " << it.second << endl;

        for (int i = 0; i < n; i++)
        {
            string word = words[i];
            int count = 0;
            for (int i = 1; i <= word.length(); i++)
            {
                count += ms.count(word.substr(0, i));
            }

            ans[i] = count;
        }

        return ans;
    }

    vector<int> soln_using_trie(vector<string> &words)
    {
        int n = words.size();
        vector<int> ans(n, 0);

        Trie trie;
        for (auto it : words)
            trie.insert(it);

        for (int i = 0; i < n; i++)
        {
            ans[i] = trie.getScore(words[i]);
        }

        return ans;
    }

public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        return solve(words);
    }
};

int main()
{

    return 0;
}