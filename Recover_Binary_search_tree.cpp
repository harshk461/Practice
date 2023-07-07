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
    TreeNode *pred = nullptr;
    TreeNode *x = nullptr; // 1st wrong node
    TreeNode *y = nullptr; // 2nd wrond node
    void inorder(TreeNode *root, vector<int> &arr)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        if (pred && root->val < pred->val)
        {
            y = root;
            if (x == NULL)
                x = pred;
            else
                return;
        }
        pred = root;
        inorder(root->right);
    }
    void swap(TreeNode *x, TreeNode *y)
    {
        int temp = x->val;
        x->val = y->val;
        y->val = temp;
    }

public:
    void recoverTree(TreeNode *root)
    {
        inorder(root);
        swap(x, y);
    }
};

int main()
{

    return 0;
}