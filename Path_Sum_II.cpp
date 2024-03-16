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
    vector<vector<int>> ans;
    void dfs(TreeNode *node, int target, int sum, vector<int> curr)
    {
        if (node->left == NULL && node->right == NULL && target == sum)
        {
            ans.push_back(curr);
            return;
        }

        if (node->val > target)
            return;

        if (node->left)
        {
            curr.push_back(node->left->val);
            dfs(node->left, target - node->left->val, curr);
            curr.pop_back();
        }
        if (node->right)
        {
            curr.push_back(node->left->val);
            dfs(node->left, target - node->right->val, curr);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return ans;
        // if (root->val < targetSum)
        //     return ans;

        vector<int> curr;
        int sum = root->val;
        curr.push_back(root->val);
        dfs(root, targetSum, sum, curr);
        return ans;
    }
};

int main()
{

    return 0;
}