#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

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
private:
    TreeNode *buildTree(int pre_start, int pre_end, int post_start, vector<int> &preorder, unordered_map<int, int> &mapping)
    {
        if (pre_start > pre_end)
            return NULL;

        if (pre_start == pre_end)
            return new TreeNode(preorder[pre_start]);

        int left_root = preorder[pre_start + 1];
        int num_of_nodes_in_left = mapping[left_root] - post_start + 1;

        TreeNode *root = new TreeNode(preorder[pre_start]);

        root->left = buildTree(pre_start + 1, pre_start + num_of_nodes_in_left, post_start, preorder, mapping);
        root->right = buildTree(pre_start + num_of_nodes_in_left + 1, pre_end, post_start + num_of_nodes_in_left, preorder, mapping);

        return root;
    }

public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        int n = preorder.size();
        unordered_map<int, int> mapping;

        for (int i = 0; i < n; i++)
        {
            mapping[postorder[i]] = i;
        }

        return buildTree(0, n - 1, 0, preorder, mapping);
    }
};

int main()
{

    return 0;
}