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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode *> q({root});
        while (!q.empty())
        {
            vector<int> currLevel;
            for (int i = q.size(); i > 0; --i)
            {
                TreeNode *node = q.front();
                q.pop();
                currLevel.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.push_back(currLevel);
        }
        return ans;
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> levelOrderArray = levelOrder(root);

        reverse(levelOrderArray.begin(), levelOrderArray.end());

        return levelOrderArray;
    }
};

int main()
{

    return 0;
}