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
    void dfs(TreeNode *root, int depth, vector<int> &ans)
    {
        if (root == NULL)
            return;
        if (depth == ans.size())
            ans.push_back(root->val);
        dfs(root->right, depth + 1, ans);
        dfs(root->left, depth + 1, ans);
    }

public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
};

int main()
{

    return 0;
}