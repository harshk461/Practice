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
    vector<vector<int>> LevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        // q.push(NULL);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            while (size > 0)
            {
                TreeNode *node = q.front();
                q.pop();
                temp.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                size--;
            }
            ans.push_back(temp);
        }

        return ans;
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};

        vector<vector<int>> level = LevelOrder(root);
        for (int i = 0; i < level.size(); i++)
        {
            if (i % 2 != 0)
            {
                vector<int> temp = level[i];
                reverse(temp.begin(), temp.end());
                level[i] = temp;
            }
        }

        return level;
    }
};

int main()
{

    return 0;
}