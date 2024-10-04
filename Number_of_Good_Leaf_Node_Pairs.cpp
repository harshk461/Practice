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
private:
    int count = 0;
    vector<int> solve(TreeNode *root, int distance)
    {
        // when node is null
        if (root == NULL)
            return {0};

        // when we are at leaf node then distance is one
        if (root->left == NULL && root->right == NULL)
            return {1};

        vector<int> left = solve(root->left, distance);
        vector<int> right = solve(root->right, distance);

        for (auto ix : left)
        {
            for (auto iy : right)
            {
                if (ix > 0 && iy > 0)
                    if (ix + iy <= distance)
                        count++;
            }
        }

        vector<int> ans;
        for (auto ix : left)
            if (ix > 0 && ix < distance)
                ans.push_back(ix + 1);

        for (auto iy : right)
            if (iy > 0 && iy < distance)
                ans.push_back(iy + 1);

        return ans;
    }

public:
    int countPairs(TreeNode *root, int distance)
    {
        solve(root, distance);
        return count;
    }
};

int main()
{

    return 0;
}