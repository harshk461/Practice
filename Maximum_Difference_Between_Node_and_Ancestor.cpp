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
    void dfs(TreeNode *root, int maxi, int mini, int &ans)
    {
        if (root == NULL)
            return;

        if (maxi != INT_MIN || mini != INT_MAX)
            ans = max(ans, {abs(root->val - maxi), abs(root->val - mini)});

        maxi = max(maxi, root->val);
        mini = min(mini, root->val);
        if (root->left)
            dfs(root->left, maxi, mini, ans);

        if (root->right)
            dfs(root->right, maxi, mini, ans);
    }

public:
    int maxAncestorDiff(TreeNode *root)
    {
        int ans = 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        dfs(root, maxi, mini, ans);
        return ans;
    }
};

int main()
{

    return 0;
}