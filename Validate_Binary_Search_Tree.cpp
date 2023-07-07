#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
                                                                                                                                                                                                  *
};

class Solution
{
private:
    bool isValid(TreeNode *root, TreeNode *minNode, TreeNode *maxnode)
    {
        if (root == NULL)
            return true;
        if (minNode && root->val <= minNode->val)
            return false;
        if (maxnode && maxnode->val <= root->val)
            return false;

        return isValid(root->left, minNode, root) &&
               isValid(root->right, root, maxnode);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return isValid(root, NULL, NULL);
    }
};
int main()
{

    return 0;
}