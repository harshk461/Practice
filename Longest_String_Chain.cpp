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

class Solution
{
private:
    bool check(string &s1, string &s2)
    {
        if (s1.size() != s2.size() + 1)
            return false;

        int i = 0, j = 0;
        while (i < s1.size())
        {
            if (j < s2.size() && s1[i] == s2[j])
                i++, j++;
            else
                i++;
        }

        if (i == s1.size() && j == s2.size())
            return true;

        return false;
    }

public:
    bool comp(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string> &words)
    {

        sort(words.begin(), words.end(), comp);
        // Modified LIS
        int n = words.size();
        vector<int> dp(n, 1);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (check(words[i], words[prev]))
                    dp[i] = max(dp[i], 1 + dp[prev]);
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

int main()
{

    return 0;
}