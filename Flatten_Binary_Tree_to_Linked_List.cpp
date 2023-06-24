#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        stack<TreeNode *> stack{{root}};

        while (!stack.empty())
        {

            root = stack.top();
            stack.pop();

            if (root->right)
            {
                stack.push(root->right);
            }
            if (root->left)
            {
                stack.push(root->left);
            }
            if (!stack.empty())
            {
                root->right = stack.top();
            }
            root->left = NULL;
        }
    }
};
int main()
{

    return 0;
}