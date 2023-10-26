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
    bool dfs(TreeNode *root, int curr, int target)
    {
        if (!root->left && !root->right)
        {
            if (target == (curr + root->val))
                return true;
            return false;
        }

        if (root->left)
            if (dfs(root->left, curr + root->val, target))
                return true;

        if (root->right)
            if (dfs(root->right, curr + root->val, target))
                return true;
        return false;
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;

        return dfs(root, 0, targetSum);
    }
};

int main()
{

    return 0;
}