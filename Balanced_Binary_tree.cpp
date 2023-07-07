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
    int getHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

public:
    bool isBalanced(TreeNode *root)
    {
        if (root = NULL)
            return true;
        return abs(getHeight(root->left) - getHeight(root->right)) <= 1 &&
               isBalanced(root->left) && isBalanced(root->right);
    }
};

int main()
{

    return 0;
}