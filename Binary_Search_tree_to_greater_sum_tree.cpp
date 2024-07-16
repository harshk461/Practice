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
    void Reverseinorder(TreeNode *root, int &prefix)
    {
        if (root == NULL)
            return;
        Reverseinorder(root->right, prefix);

        root->val += prefix;
        prefix = root->val;

        Reverseinorder(root->left, prefix);
    }

    void inorder(TreeNode *root, vector<int> &arr)
    {
        if (root == NULL)
            return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    TreeNode *solve(TreeNode *root)
    {
        vector<int> arr;
        inorder(root, arr);
        int n = arr.size();
        vector<int> suffix(n, 0);

        suffix[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = suffix[i] + arr[i];

        for (auto it : suffix)
            cout << it << " ";

        return root;
    }

public:
    TreeNode *bstToGst(TreeNode *root)
    {
        int prefix = 0;
        Reverseinorder(root, prefix);
        return solve(root);
    }
};

int main()
{

    return 0;
}