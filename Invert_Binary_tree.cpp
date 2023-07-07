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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        TreeNode *leftSide = root->left;
        TreeNode *rightSide = root->right;

        root->left = rightSide;
        root->right = leftSide;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        return root;
    }
};

int main()
{

    return 0;
}