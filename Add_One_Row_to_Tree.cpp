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
    TreeNode *SolveWithStack(TreeNode *root, int val, int depth)
    {

        stack<pair<TreeNode *, int>> st;
        st.push({root, 1});

        while (!st.empty())
        {
            auto top = st.top();
            st.pop();
            TreeNode *node = top.first;
            int level = top.second;

            if (level == depth - 1)
            {
                TreeNode *leftSide = node->left;
                TreeNode *rightSide = node->right;

                node->left = new TreeNode(val);
                node->right = new TreeNode(val);
                node->left->left = leftSide;
                node->right->right = rightSide;
            }
            else
            {
                if (node->left != NULL)
                    st.push({node->left, level + 1});
                if (node->right != NULL)
                    st.push({node->right, level + 1});
            }
        }

        return root;
    }

    TreeNode *solveByRecursion(TreeNode *root, int val, int depth, int curr_level)
    {
        if (root == NULL)
            return NULL;

        if (curr_level == depth - 1)
        {
            TreeNode *leftSide = root->left;
            TreeNode *rightSide = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = leftSide;
            root->right->right = rightSide;

            return root;
        }

        root->left = solveByRecursion(root->left, val, depth, curr_level + 1);
        root->right = solveByRecursion(root->right, val, depth, curr_level + 1);

        return root;
    }

public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            // when we have to add a node at depth 1 or level 0
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }

        return SolveWithStack(root, val, depth);
    }
};

int main()
{

    return 0;
}