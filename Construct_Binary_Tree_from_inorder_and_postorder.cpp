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
    TreeNode *InorderToTree(vector<int> &inorder, int l, int r)
    {
        if (l > r)
            return NULL;
        int m = l + (r - l) / 2;

        return new TreeNode(inorder[m], InorderToTree(inorder, l, m - 1), InorderToTree(inorder, m + 1, r));
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return InorderToTree(inorder, 0, inorder.size() - 1);
    }
};

int main()
{

    return 0;
}