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
    int ans = 0;
    void dfs(TreeNode *root, int parent)
    {
        if (root == NULL)
            return;

        int left = dfs(root->left, root->val);
        int right = dfs(root->right, root->val);

        ans = max(ans, left + right);

        return root->val == parent ? max(left, right) + 1 : 0;
    }

public:
    int longestUnivaluePath(TreeNode *root)
    {
        // initially root doesnt have any parent ;)
        dfs(root, -1);
        return ans;
    }
};

int main()
{

    return 0;
}