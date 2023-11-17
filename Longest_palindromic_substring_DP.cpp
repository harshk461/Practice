#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool solve(int i, int j, string &s, vector<int> ans)
    {
        if (l >= r)
            return true;

        bool found = false;
        if (s[i] == s[j])
            found = true && solve(i + 1, j - 1, s, ans);

        solve(i + 1, j, s, ans);
        solve(i, j - 1, s, ans);

        if (found && (r - 1 + 1) > ans[2])
            ans = {l, r, (r - l + 1)};

        return found;
    }

public:
    string longestPalindrome(string str)
    {
        int n = str.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int x, y, maxi = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j <= n - 1; j++)
            {
                if (i == j)
                    dp[i][j] = true;
                else if (s[i] == s[j])
                {
                    if (j - i == 1)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
                if (dp[i][j] && j - i >= max)
                {
                    max = j - i;
                    x = i;
                    y = j;
                }
            }
        }
        return str.substr(x, y - x + 1);
    }
};

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int memo[1001][1001];
        memset(memo, -1, sizeof(memo));
        vector<int> answer = {0, 0, 1};
        helper(0, s.size() - 1, s, memo, answer);
        return s.substr(answer[0], answer[2]);
    }

    bool helper(int l, int r, string &s, int memo[][1001], vector<int> &answer)
    {
        if (memo[l][r] != -1)
        {
            return memo[l][r];
        }

        if (l >= r)
        {
            return true;
        }

        bool found = false;
        if (s[l] == s[r])
        {
            found = true && helper(l + 1, r - 1, s, memo, answer);
        }

        helper(l + 1, r, s, memo, answer);
        helper(l, r - 1, s, memo, answer);

        if (found && (r - l + 1) > answer[2])
        {
            answer = {l, r, (r - l + 1)};
        }
        memo[l][r] = found;

        return found;
    }
};

int main()
{

    return 0;
}