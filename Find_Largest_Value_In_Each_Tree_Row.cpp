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
    void levelOrderTraversal(TreeNode *root, vector<vector<int>> &arr)
    {
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> tempArr;
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            if (temp == NULL)
            { // purana level complete ho gya h
                arr.push_back(tempArr);
                tempArr.clear();
                if (!q.empty()) // queue still have some child node
                {
                    q.push(NULL);
                }
            }

            else
            {
                tempArr.push_back(temp->val);
                if (temp->left)
                {
                    q.push(temp->left);
                }

                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
    }

    vector<int> solve(TreeNode *root)
    {
        if (root == NULL)
            return {};

        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int curr_lvl_size = q.size();
            int max_val = INT_MIN;

            for (int i = 0; i < curr_lvl_size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                max_val = max(max_val, node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right)
            }
            ans.push_back(max_val);
        }

        return ans;
    }

public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<vector<int>> arr;
        vector<int> ans;
        levelOrderTraversal(root, arr);
        for (auto it : arr)
        {
            int temp = *max_element(it.begin(), it.end());
            ans.push_back(temp);
        }

        return ans;
    }
};

int main()
{

    return 0;
}