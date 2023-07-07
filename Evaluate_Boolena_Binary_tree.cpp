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
public:
    bool evaluateTree(TreeNode *root)
    {
        if (root->val > 2)
            return root->val;
        if (root->val == 2) // OR operation
            return evaluateTree(root->left) || evaluateTree(root->right);
        //AND Operation
        return evaluateTree(root->left) && evaluateTree(root->right);
    }
};

int main()
{

    return 0;
}