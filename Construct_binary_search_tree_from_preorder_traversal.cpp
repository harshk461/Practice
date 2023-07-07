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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode *> st({root});
        for (int i = 1; i < preorder.size(); i++)
        {
            TreeNode *parent = st.top();
            TreeNode *child = new TreeNode(preorder[i]);

            // adjust parent
            while (!st.empty() && st.top()->val < child->val)
                parent = st.top(), st.pop();

            if (parent->val > child->val)
                parent->left = child;
            else
                parent->right = child;
            st.push(child);
        }
        return root;
    }
};

int main()
{

    return 0;
}