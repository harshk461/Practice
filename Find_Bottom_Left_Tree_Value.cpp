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
public:
    int findBottomLeftValue(TreeNode *root)
    {
        vector<vector<int>> ans;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            vector<int> curr;
            for (int i = 0; i < q.size(); i++)
            {
                auto front = q.front();
                q.pop();

                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);

                curr.push_back(front->val);
            }
            ans.push_back(curr);
        }

        return ans[ans.size() - 1][0];
    }
};

int main()
{

    return 0;
}