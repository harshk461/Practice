#include <iostream>
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
    TreeNode *solve(TreeNode *root, int target)
    {

        if (root->left)
            root->left = solve(root->left, target);
        if (root->right)
            root->right = solve(root->right, target);
        if (root->left == NULL && root->right == NULL && root->val == target)
            return NULL;
        if (root->left == NULL && root->right == NULL && root->val != target)
            return root;
        return root;
    }

    TreeNode *solve2(TreeNode *root, int target)
    {

        if (root->left)
            root->left = solve2(root->left, target);
        if (root->right)
            root->right = solve2(root->right, target);

        if (root->left == NULL && root->right == NULL && root->val == target)
            return NULL;

        return root;
    }

public:
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        TreeNode *dummy = new TreeNode(10000);
        dummy->left = root;
        solve(dummy, target);
        if (dummy->left == NULL && dummy->right == NULL)
            return NULL;
        return solve2(root, target);
    }
};

int main()
{

    return 0;
}