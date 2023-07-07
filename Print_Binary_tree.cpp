#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
                                                                                                                                                                                                  *
};

class Solution
{
public:
    vector<vector<string>> printTree(TreeNode *root)
    {
        int m = maxHeight(root);
        int n = pow(2, m) - 1;
        vector<vector<string>> ans(m, vector<string>(n));
        dfs(root, 0, 0, ans[0].size() - 1, ans);
        return ans;
    }

private:
    int maxHeight(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        return 1 + max(maxHeight(root->left), maxHeight(root->right));
    }

    void dfs(TreeNode *root, int row, int left, int right, vector<vector<string>> &ans)
    {
        if (root == NULL)
        {
            return NULL;
        }

        int mid = left + (right - left) / 2;
        ans[row][mid] = to_string(root->val);
        dfs(root->left, row + 1, left, mid - 1, ans);
        dfs(root->right, row + 1, mid + 1, right, ans);
    }
};

int main()
{

    return 0;
}