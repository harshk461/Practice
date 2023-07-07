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

    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &index, int start, int end, int n, unordered_map<int, int> &map)
    {
        if (index >= n || start > end)
            return NULL;

        int element = preorder[index];
        index++;
        TreeNode *root = new TreeNode(element);

        int posn = map[element];

        root->left = solve(preorder, inorder, index, start, posn - 1, n, map);
        root->right = solve(preorder, inorder, index, posn + 1, end, n, map);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> map;
        createMapping(inorder, map);
        int index = 0;
        int n = inorder.size();
        TreeNode *ans = solve(preorder, inorder, index, 0, n - 1, n, map);
        return ans;
    }
};

int main()
{

    return 0;
}