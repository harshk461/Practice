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
    void dfs(TreeNode *root, string curr, string &ans)
    {
        if (root == NULL)
            return;
        curr += char(root->val + 'a');

        // leaf node
        if (root->left == NULL && root->right == NULL)
        {
            reverse(curr.begin(), curr.end());
            if (ans == "" || ans > curr)
                ans = curr;

            reverse(curr.begin(), curr.end()); // backtrack reverse
        }

        if (root->left)
            dfs(root->left, curr, ans);
        if (root->right)
            dfs(root->right, curr, ans);
    }

public:
    string smallestFromLeaf(TreeNode *root)
    {
        string curr = "";
        string ans;
        dfs(root, curr, ans);
        return ans;
    }
};

int main()
{

    return 0;
}