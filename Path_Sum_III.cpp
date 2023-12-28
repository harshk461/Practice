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
    int dfs(TreeNode *root, int target)
    {
        int count = 0;
        if (root->val == target)
            count++;
        if (root->left)
            count += dfs(root->left, target - root->val);
        if (root->right)
            count += dfs(root->right, target - root->val);

        return count;
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return 0;
        int count = dfs(root, targetSum);
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }
};

int main()
{

    return 0;
}