#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    TreeNode *solve(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL || root == p || root = q)
            return root;

        TreeNode *leftSubtree = solve(root->left, p, q);
        TreeNode *rightSubtree = solve(root->right, p, q);

        if (leftSubtree == NULL && rightSubtree != NULL)
            return rightSubtree;

        if (rightSubtree == NULL && leftSubtree != NULL)
            return leftSubtree;

        // when both left and right subtree exist we return the value of previous recursion call
        else
            return root;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        return solve(root, p, q);
    }
};

int main()
{

    return 0;
}