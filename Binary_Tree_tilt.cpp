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
    int sum(TreeNode *root, int &ans)
    {
        if (root == NULL)
            return 0;
        int l = sum(root->left, ans);
        int r = sum(root->right, ans);
        ans += abs(l - r);
        return root->val + l + r;
    }

public:
    int findTilt(TreeNode *root)
    {
        int ans = 0;
        sum(root, ans);
        return ans;
    }
};

int main()
{

    return 0;
}