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
        if (root = NULL)
        {
            return;
        }

        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }

public:
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries)
    {
        vector<int> inorder_array;
        inorder(root, inorder_array);
        vector<vector<int>> ans;
        for (auto num : queries)
        {
            auto it = lower_bound(inorder_array.begin(), inorder_array.end(), num);
            if (it != inorder_array.cend() && *it == num)
                ans.push_back({num, num});
            else
            {
                ans.push_back({it == inorder_array.cbegin() ? -1 : *prev(it),
                               it == inorder_array.cend() ? -1 : *it});
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}