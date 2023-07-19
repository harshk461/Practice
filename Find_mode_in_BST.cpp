#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    void inorder(TreeNode *root, vector<int> &arr)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return {root->val};
        }
        vector<int> ans;
        unordered_map<int, int> map;
        vector<int> inorderArr;
        inorder(root, inorderArr);
        for (auto i : inorderArr)
        {
            map[i]++;
        }

        int maxCount = INT_MIN;
        for (auto i : map)
        {
            maxCount = max(maxCount, i.second);
        }
        for (auto i : map)
        {
            if (i.second >= maxCount)
                ans.push_back(i.first);
        }
        return ans;
    }
};

int main()
{

    return 0;
}