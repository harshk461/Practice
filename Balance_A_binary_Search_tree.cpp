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
    void inorder(TreeNode *root, vector<int> &arr)
    {
        if (root == NULL)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    TreeNode *BuildTree(vector<int> arr, int low, int high)
    {
        if (low > high)
            return NULL;
        int m = low + (high - low) / 2;

        return new TreeNode(arr[m], BuildTree(arr, low, m - 1), BuildTree(arr, m + 1, high));
    }

public:
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> arr;
        inorder(root, arr);
    }
};

int main()
{

    return 0;
}