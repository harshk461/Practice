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
    void inorder_sum(TreeNode *root, int &sum)
    {
        if (root == NULL)
            return;

        if (root->left != NULL && root->left->right == NULL && root->left->left == NULL)
            sum += root->left->val;

        inorder_sum(root->left, sum);
        inorder_sum(root->right, sum)
    }

public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        int ans = 0;
        inorder_sum(root, ans);
        return ans;
    }
};

int main()
{

    return 0;
}