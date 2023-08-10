#include <bits/stdc++.h>
using namespace std;

int solve(string a, string b, string c, vector<vector<vector<int>>> &dp)
{
    for (int i = 1; i <= a.length(); i++)
    {
        for (int j = 1; j <= b.length(); j++)
        {
            for (int k = 1; k <= c.length(); k++)
            {
                if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1])
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                else
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
            }
        }
    }

    return dp[a.length()][b.length()][c.length()];
}

int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    int n = A.length(), m = B.length(), o = C.length();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(o + 1, 0)));
    return solve(A, B, C, dp);
}

int main()
{
    cout << LCSof3("geeks", "geeksfor", "geeksforgeeks", 5, 7, 13);
    return 0;
}