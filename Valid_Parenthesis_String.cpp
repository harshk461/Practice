#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int index, int move, string s, vector<vector<int>> dp)
    {
        if (index == s.length())
            return (move == 0);

        if (dp[index][move] != -1)
            return dp[index][move];

        bool ans = false;
        if (s[index] == '*')
        {
            ans |= solve(index + 1, move + 1, s, dp); // '('
            if (move)
                ans |= solve(index + 1, move - 1, s, dp); //')'
            ans |= solve(index + 1, move, s, dp);
        }
        else
        {
            if (s[index] == '(')
                ans = solve(index + 1, move + 1, s, dp);
            else
                ans = solve(index + 1, move - 1, s, dp);
        }
        return dp[index][move] = ans;
    }

    bool solve2(int index, int openBracket, string s, vector<vector<int>> &dp)
    {
        if (index == s.length())
            return (openBracket == 0);

        if (dp[index][openBracket] != -1)
            return dp[index][openBracket];

        if (s[index] == '(')
            dp[index][openBracket] = solve2(index + 1, openBracket + 1, s, dp);
        else if (s[index] == ')')
            dp[index][openBracket] = solve2(index + 1, openBracket - 1, s, dp);
        else
            dp[index][openBracket] = (solve2(index + 1, openBracket + 1, s, dp) || solve2(index + 1, openBracket, s, dp) || solve2(index + 1, openBracket - 1, s, dp));
        return dp[index][openBracket];
    }

public:
    bool checkValidString(string s)
    {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        return solve(0, 0, s, dp);
    }
};

int main()
{

    return 0;
}