#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct BST
{
    bool isBST;
    int max;
    int min;
    int sum;

    BST() : isBST(false) {}
    BST(bool isBST, int max, int min, int sum) : isBST(false), max(max), min(min), sum(sum) {}
};

class Solution
{
private:
    BST traverse(TreeNode *root, int &ans)
    {
        if (root == NULL)
        {
            return BST(true, INT_MIN, INT_MAX, 0);
        }

        BST left = traverse(root->left, ans);
        BST right = traverse(root->right, ans);

        if (!left.isBST || !right.isBST)
            return BST();

        if (root->val <= left.max || root->val >= right.min)
            return BST();

        // root is valid BST

        int sum = root->val + left.sum + right.sum;
        ans = max(ans, sum);
        return BST(true, max(root->val, right.max), min(root->val, left.min), sum);
    }

public:
    int maxSumBST(TreeNode *root)
    {
        int ans = 0;
        traverse(root, ans);
        return ans;
    }
};

int main()
{

    return 0;
}