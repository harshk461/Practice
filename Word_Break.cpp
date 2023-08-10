#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int i, string s, set<string> &wordDict)
    {
        if (i == s.length())
            return 1;
        string temp;
        for (int j = i; j < s.length(); j++)
        {
            temp += s[j];
            if (wordDict.find(temp) != wordDict.end())
                if (solve(j + 1, s, wordDict))
                    return 1;
        }
        return 0;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> word_set(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n + 1);
        dp[0] = true;
        int i, j;
        for (i = 0; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && word_set.find(s.substr(j, i - j)) != word_set.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};

int main()
{

    return 0;
}