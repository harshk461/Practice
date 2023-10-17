#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isPalindrome(string s)
    {
        int i = 0, j = s.length() - 1;
        string temp = s;
        while (i < j)
        {
            swap(s[i], s[j]);
            i++, j--;
        }
        return temp == s;
    }
    int brute(string s)
    {
        int count = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            string temp;
            for (int j = i; j < n; j++)
            {
                temp += s[j];
                if (isPalindrome(temp))
                    count++;
            }
        }
        return count;
    }
    int solve(int i, int j, string s, vector<vector<int>> &dp)
    {
        if (i > j)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = solve(i + 1, j - 1, s, dp);
        return dp[i][j] = 0;
    }

public:
    int countSubstrings(string s)
    {
        int count = 0;
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                count += solve(i, j, s, dp);
        return count;
    }
};

int main()
{

    return 0;
}