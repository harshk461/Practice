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
    int dfs(TreeNode *root, int maxi)
    {
        if (root == NULL)
            return 0;
        int count = 0;
        if (root->left)
        {
            if (root->left->val >= maxi)
                count += 1 + dfs(root->left, root->left->val);
            else
                count += dfs(root->left, maxi);
        }
        if (root->right)
        {
            if (root->right->val >= maxi)
                count += 1 + dfs(root->right, root->right->val);
            else
                count += dfs(root->right, maxi);
        }

        return count;
    }

public:
    int goodNodes(TreeNode *root)
    {
        // int count = 1; // root is always good
        return 1 + dfs(root, root->val);
    }
};

int main()
{

    return 0;
}