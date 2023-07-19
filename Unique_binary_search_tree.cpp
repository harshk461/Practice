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

        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};

int main()
{

    return 0;
}