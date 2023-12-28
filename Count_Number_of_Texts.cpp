#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int MOD = 1e9 + 7;
    int solve(int i, string &s, vector<int> &dp)
    {
        if (i == s.length())
            return 1;

        if (dp[i] != -1)
            return dp[i];

        int maxKeyPress = (s[i] == '7' || s[i] == '9') ? 4 : 3;
        long long currIndex = i;
        long long pressFreq = 1;
        long long ans = 0;

        while (pressFreq <= maxKeyPress && s[currIndex] == s[i])
        {
            currIndex++;
            ++pressFreq;
            ans += solve(currIndex, s, dp) % MOD;
        }

        return dp[i] = ans % MOD;
    }

    int solve2(int i, string &s, vector<int> &mapping, vector<int> &dp)
    {
        if (i == s.length())
            return 1;

        if (dp[i] != -1)
            return dp[i];

        int digit = s[i] - '0';
        long count = 0;
        for (int index = 0; index < mapping[digit] && i + index < s.length() && s[i] == s[index + i]; index++)
        {
            count += solve2(i + index + 1, s, mapping, dp);
            count %= MOD;
        }

        return dp[i] = count;
    }

public:
    int countTexts(string pressedKeys)
    {
        vector<int> dp(pressedKeys.length() + 1, -1);
        vector<int> mapping = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
        return solve2(0, pressedKeys, mapping, dp);
        // return solve(0, pressedKeys, dp);
    }
};

int main()
{

    return 0;
}