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
    void dfs(TreeNode *root, int level, vector<int> &level_Sum)
    {
        if (root == NULL)
        {
            return;
        }
        if (level_Sum.size() == level)
        {
            level_Sum.push_back(0);
        }
        level_Sum[level] += root->val;
        dfs(root->left, level + 1, level_Sum);
        dfs(root->right, level + 1, level_Sum);
    }

public:
    int maxLevelSum(TreeNode *root)
    {
        vector<int> levelSum;
        dfs(root, 0, levelSum);
        return 1 + max_element(levelSum.begin(), levelSum.end() - levelSum.begin());
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    return 0;
}