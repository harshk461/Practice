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
    void inorder(TreeNode *root, priority_queue<int> &arr)
    {
        if (root == NULL)
            return;
        inorder(root->left, arr);
        arr.push(root->val);
        inorder(root->right, arr);
    }

public:
    int findSecondMinimumValue(TreeNode *root)
    {
        priority_queue<int> arr;
        inorder(root, arr);

        arr.pop();
        if (!arr.empty())
            return arr.top();
        return -1;
    }
};

int main()
{

    return 0;
}