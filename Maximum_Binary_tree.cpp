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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    TreeNode *solve(int start, int end,
                    vector<int> &nums, unordered_map<int, int> &mapping)
    {
        if (start > end)
            return NULL;

        int maxi = *max_element(nums.begin() + start, nums.begin() + end + 1);
        cout << start << " " << end << endl;
        TreeNode *node = new TreeNode(maxi);
        node->left = solve(start, mapping[maxi] - 1, nums, mapping);
        node->right = solve(mapping[maxi] + 1, end, nums, mapping);

        return node;
    }

public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        unordered_map<int, int> mapping;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            mapping[nums[i]] = i;

        int maxi = *max_element(nums.begin(), nums.end());
        // cout<<maxi<<" ";
        TreeNode *root = new TreeNode(maxi);
        root->left = solve(0, mapping[maxi] - 1, nums, mapping);
        root->right = solve(mapping[maxi] + 1, n - 1, nums, mapping);

        return root;
    }
};

int main()
{

    return 0;
}