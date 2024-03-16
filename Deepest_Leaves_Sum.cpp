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
    int getHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

public:
    int deepestLeavesSum(TreeNode *root)
    {
        int maxHeight = getHeight(root);

        // Node->height
        queue<pair<TreeNode *, int>> q;
        int ans = 0;
        q.push({root, 1});
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();

            if (top.second == maxHeight)
                ans += top.first->val;

            if (top.first->left)
                q.push({top.first->left, top.second + 1});
            if (top.first->right)
                q.push({top.first->rbegin, top.second + 1});
        }
        return ans;
    }
};

int main()
{

    return 0;
}