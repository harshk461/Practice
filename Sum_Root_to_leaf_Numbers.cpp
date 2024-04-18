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
    void dfs(TreeNode *root, string temp, vector<string> &ans)
    {
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(temp);
            return;
        }

        if (root->left)
        {
            temp.push_back(root->left->val + '0');
            dfs(root->left, temp, ans);
            temp.pop_back();
        }

        if (root->right)
        {
            temp.push_back(root->right->val + '0');
            dfs(root->right, temp, ans);
            temp.pop_back();
        }
    }

public:
    int sumNumbers(TreeNode *root)
    {
        vector<string> ans;

        string temp = "";
        dfs(root, temp, ans);

        int res = 0;
        for (auto it : ans)
            res += stoi(it);
        return res;
    }
};

int main()
{

    return 0;
}