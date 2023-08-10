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
    int f(TreeNode *root)
    {
        if (root == NULL)
            return {0, 0};

        vector<int> res(2);
        vector<int> left = f(root->left);
        vector<int> right = f(root->right);

        // result[0] is when root is selected, result[1] is when not.
        result[0] = root->val + left[1] + right[1];
        right[1] = max(left[0], left[1]) + max(right[0], right[1]);

        return result;
    }

public:
    int rob(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        vector<int> res = f(root);
        return max(res[0], res[1]);
    }
};

int main()
{

    return 0;
}