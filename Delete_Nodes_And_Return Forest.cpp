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
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        if (!root)
            return {};

        unordered_set<int> st(to_delete.begin(), to_delete.end());
        vector<TreeNode *> result;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *cur_node = q.front();
            q.pop();

            if (cur_node->left)
            {
                q.push(cur_node->left);
                if (st.count(cur_node->left->val))
                    cur_node->left = nullptr;
            }

            if (cur_node->right)
            {
                q.push(cur_node->right);
                if (st.count(cur_node->right->val))
                    cur_node->right = nullptr;
            }

            if (st.count(cur_node->val))
            {
                if (cur_node->left)
                    result.push_back(cur_node->left);
                if (cur_node->right)
                    result.push_back(cur_node->right);
            }
            else if (result.empty())
                result.push_back(cur_node);
        }

        return result;
    }
};

int main()
{

    return 0;
}