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
    void createMapping(vector<int> &inorder, unordered_map<int, int> &map)
    {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
        {
            map[inorder[i]] = i;
        }
    }

    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int &postIndex, int start, int end, unordered_map<int, int> &map)
    {
        if (postIndex < 0 || start > end)
            return NULL;

        int element = postorder[postIndex--];
        TreeNode *root = new TreeNode(element);

        int posn = map[element];
        root->right = solve(inorder, postorder, postIndex, posn + 1, end, map);
        root->left = solve(inorder, postorder, postIndex, start, posn - 1, map);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        int postIndex = n - 1;
        unordered_map<int, int> map;
        createMapping(inorder, map);
        TreeNode *ans = solve(inorder, postorder, postIndex, 0, n - 1, map);
        return ans;
    }
};

int main()
{

    return 0;
}