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
    bool isOkay(TreeNode *root, int target)
    {
        if (root == NULL)
            return false;
        if (target == 0)
            return true;
        if (target < 0)
            return false;

        bool ans = false;
        if (root->left)
        {
            ans |= isOkay(root->left, target - root->left->val);
        }

        if (root->left)
        {
            ans |= isOkay(root->right, target - root->right->val);
        }

        return ans;
    }

    int dfs(TreeNode *root, int target)
    {
        if (root == NULL)
            return 0;

        int count = 0;
        if (root->left)
        {
            if (isOkay(root->left, target))
                count++;
            else
                count += dfs(root->left, target);
        }

        if (root->right)
        {
            if (isOkay(root->right, target))
                count++;
            else
                count += dfs(root->right, target);
        }

        return count;
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        return dfs(root, targetSum);
    }
};

int main()
{

    return 0;
}