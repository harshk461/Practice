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
    // dirn->0(left) 1(right)
    int ans = 0;
    void countZigZag(TreeNode *root, bool dirn, int steps)
    {
        if (root == NULL)
            return;

        ans = max(ans, steps);
        // means go right
        if (dirn)
        {
            countZigZag(root->left, false, steps);
            countZigZag(root->right, true, steps + 1);
        }
        else
        {
            countZigZag(root->left, false, 1);
            countZigZag(root->right, true, steps + 1);
        }
    }

public:
    int longestZigZag(TreeNode *root)
    {
        countZigZag(root, false, 0);
        countZigZag(root.true, 0);
        return ans;
    }
};

int main()
{

    return 0;
}