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
    string preorder(TreeNode *root)
    {
        if (root == NULL)
            return "";

        string rootS = to_string(root->val);
        if (root->right)
            return rootS + "(" + solve(root->left) + ")(" + solve(root->right) + ")";
        if (root->left)
            return rootS + "(" + solve(root->left) + ")";

        return rootS + "";
    }

public:
    string tree2str(TreeNode *root)
    {
        return solve(root);
    }
};

int main()
{

    return 0;
}