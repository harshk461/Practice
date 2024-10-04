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
    int ans = 0;
    int string_to_number(string s)
    {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                ans += pow(2, n - i - 1);
            }
        }

        return ans;
    }

    void dfs(TreeNode *root, string curr)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            curr.push_back(root->val + '0');
            // cout<<curr<<" ";
            ans += string_to_number(curr);
            return;
        }

        if (root->left)
        {
            curr.push_back(root->val + '0');
            dfs(root->left, curr);
            curr.pop_back();
        }
        if (root->right)
        {

            curr.push_back(root->val + '0');
            dfs(root->right, curr);
            curr.pop_back();
        }
    }

public:
    int sumRootToLeaf(TreeNode *root)
    {
        string curr = "";
        dfs(root, curr);
        return ans;
    }
};

int main()
{

    return 0;
}