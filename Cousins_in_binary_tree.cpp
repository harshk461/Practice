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
public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        if (root == NULL)
            return false;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            bool isX = false;
            bool isY = false;
            for (int i = q.size(); i > 0; --i)
            {
                root = q.front();
                q.pop();

                if (root->val == x)
                    isX = true;
                else if (root->val == y)
                    isY = true;
                else if (root->left && root->right)
                {
                    if (root->left->val == x && root->right->val == y)
                        return false;
                    if (root->left->val == y && root->right->val == x)
                        return false;
                }
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
            if (isX && ixY)
                return true;
            else if (isX || isY)
                return false;
        }
        return false;
    }
};

int main()
{

    return 0;
}