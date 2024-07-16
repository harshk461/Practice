#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    TreeNode *dfs(TreeNode *root, int sum, int limit)
    {
        if (root == NULL)
            return NULL;

        if (root->left == NULL && root->right == NULL)
        {
            if (sum + root->val < limit)
                return NULL;
            else
                return root;
        }

        root->left = dfs(root->left, sum + root->val, limit);
        root->right = dfs(root->right, sum + root->val, limit);

        if (root->left == NULL && root->right == NULL)
            return NULL;

        return root;
    }

public:
    TreeNode *sufficientSubset(TreeNode *root, int limit)
    {
        return dfs(root, 0, limit);
    }
};

int main()
{

    return 0;
}