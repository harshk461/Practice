#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    int solve(int n)
    {
        if (n <= 1)
            return 1;

        int ans = 0;
        // taking all i as root node
        for (int i = 0; i <= n; i++)
            ans += solve(i - 1) * solve(n - i);
        return ans;
    }
    int solveMem(int n, vector<int> &dp)
    {
        if (n <= 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int ans = 0;
        // taking all i as root node
        for (int i = 1; i <= n; i++)
            ans += solveMem(i - 1, dp) * solveMem(n - i, dp);
        return dp[n] = ans;
    }

    int solveTab(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        int ans = 0;
        // i->no. of nodes
        for (int i = 2; i <= n; i++)
            // j->which node is root node
            for (int j = 1; j <= i; j++)
                dp[i] += dp[j - 1] * dp[i - j];
        return dp[n];
    }

public:
    int numTrees(int n)
    {
        if (n == 0)
            return 1;
        int result = 0;
        for (int i = 1; i <= n; i++)
        {
            result += numTrees(i - 1) * numTrees(n - i);
        }
        return result;
    }
    int numTrees2(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 1, dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};

int main()
{

    return 0;
}