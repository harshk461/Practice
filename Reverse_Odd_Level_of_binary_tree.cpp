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
    void dfs(TreeNode *left, TreeNode *right, bool isOdd)
    {
        if (left == NULL)
            return;
        if (isOdd)
            swap(left->val, right->val);
        dfs(left->left, right->right, !isOdd);
        dfs(left->right, right->left, !isOdd);
    }

public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        dfs(root->left, root->right, true);
        return root;
    }
};

int main()
{

    return 0;
}