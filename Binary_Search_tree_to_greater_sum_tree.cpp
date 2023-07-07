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

public:
    TreeNode *bstToGst(TreeNode *root)
    {
        int prefix = 0;
        Reverseinorder(root, prefix);
        return root;
    }
};

int main()
{

    return 0;
}