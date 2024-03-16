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
    vector<vector<string>> temp;
    void dfs(TreeNode *root, vector<string> ch)
    {
        if (root->left == NULL && root->right == NULL)
        {
            temp.push_back(ch);
            return;
        }

        if (root->left)
        {
            ch.push_back(to_string(root->left->val));
            dfs(root->left, ch);
            ch.pop_back();
        }

        if (root->right)
        {
            ch.push_back(to_string(root->right->val));
            dfs(root->right, ch);
            ch.pop_back();
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (root == NULL)
            return {};

        vector<char> ch;
        ch.push_back(to_string(root->val));
        dfs(root, ch);

        vector<string> ans;
        for (auto it : temp)
        {
            string t = "";
            for (auto i : it)
            {
                t += i;
                t += "->";
            }
            ans.push_back(t.substr(0, t.length() - 2));
        }

        return ans;
    }
};

int main()
{

    return 0;
}