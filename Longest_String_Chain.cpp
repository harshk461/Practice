#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    unordered_map<string, int> chainLength;
    unordered_map<string, bool> wordSet;

    int calculateChainLength(string &word)
    {
        // word don't exist
        if (wordSet.find(word) == wordSet.end())
            return 0;

        if (chainLength.find(word) != chainLength.end())
            return chainLength[word];

        int count = 1;

        for (int i = 0; i < word.length(); i++)
        {
            string new_word = word.substr(0, i) + word.substr(i + 1);
            count = max(count, 1 + calculateChainLength(new_word));
        }
        chainLength[word] = count;
        return count;
    }

public:
    int longestStrChain(vector<string> &words)
    {
        for (auto word : words)
            wordSet[word] = true;

        int ans = -1;
        for (auto word : words)
            ans = max(ans, calculateChainLength(word));
        return ans;
    }
};

int main()
{

    return 0;
}