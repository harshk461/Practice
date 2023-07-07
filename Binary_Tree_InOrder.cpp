#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
                                                                                                                                                                                                  *
};

class Solution
{
private:
    void InOrder(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        InOrder(root->left, ans);
        ans.push_back(root->val);
        InOrder(root->right, ans);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        InOrder(root, ans);
        return ans;
    }
};
int main()
{

    return 0;
}