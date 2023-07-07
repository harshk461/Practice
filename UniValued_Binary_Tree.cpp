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

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

public:
    bool isUnivalTree(TreeNode *root)
    {
        vector<int> arr;
        inorder(root,arr);
        set<int> s(arr.begin(),arr.end());
        return s.size()==1;
    }
};

int main()
{

    return 0;
}